package server

import (
	"sync"
	"time"

	"github.com/alph4b3th/rakstar/internal/natives"
	"github.com/alph4b3th/rakstar/player" // Importando seu builder de player
	"github.com/alph4b3th/rakstar/utils"
)

type virtualPickup struct {
	id         int // ID real do SAMP (retornado pelo native)
	model      int
	pickupType int
	x, y, z    float32
	world      int
	isCreated  bool
}

var (
	// pickups armazena [ID_Interno]virtualPickup
	pickups = make(map[int]*virtualPickup)
	nextId  = 1
	mu      sync.RWMutex
)

func init() {
	tick := time.NewTicker(time.Second)
	go updatePickups(tick)
}

func updatePickups(tick *time.Ticker) {
	for range tick.C {
		mu.Lock()

		// 1. Coletar posições de todos os players conectados uma única vez para otimizar
		type pos struct{ x, y, z float32 }
		var activePlayers []pos

		for i := 0; i < 1000; i++ { // Limite padrão do SAMP
			var isConnected bool
			player.Builder().Select(i).Connected(&isConnected)
			if isConnected {
				px, py, pz, _, err := player.Builder().Select(i).Coordinate()
				if err == nil {
					activePlayers = append(activePlayers, pos{px, py, pz})
				}
			}
		}

		// 2. Processar cada pickup virtual
		for _, p := range pickups {
			anyPlayerNear := false

			// Verificar se algum player está perto deste pickup (raio de 100 metros)
			for _, pPos := range activePlayers {
				dist := utils.CalculateDistance(pPos.x, pPos.y, pPos.z, p.x, p.y, p.z)
				if dist < 100.0 {
					anyPlayerNear = true
					break
				}
			}

			// 3. Aplicar o Streaming
			if anyPlayerNear && !p.isCreated {
				p.id = natives.CreatePickup(p.model, p.pickupType, p.x, p.y, p.z, p.world)
				p.isCreated = true
			} else if !anyPlayerNear && p.isCreated {
				natives.DestroyPickup(p.id)
				p.isCreated = false
			}
		}
		mu.Unlock()
	}
}

// CreatePickup insere o pickup no sistema de streaming e retorna um ID interno
func (sb *ServerBuild) CreatePickup(model, Type int, x, y, z float32, world int) int {
	mu.Lock()
	defer mu.Unlock()

	id := nextId
	pickups[id] = &virtualPickup{
		model:      model,
		pickupType: Type,
		x:          x,
		y:          y,
		z:          z,
		world:      world,
		isCreated:  false,
	}
	nextId++
	return id
}

// DestroyPickup remove o pickup do sistema e o deleta do mapa se estiver criado
func (sb *ServerBuild) DestroyPickup(internalId int) *ServerBuild {
	mu.Lock()
	defer mu.Unlock()

	if p, ok := pickups[internalId]; ok {
		if p.isCreated {
			natives.DestroyPickup(p.id)
		}
		delete(pickups, internalId)
	}
	return sb
}
