package player

import (
	"sync"
	"time"

	"github.com/alph4b3th/rakstar/internal/natives"
	"github.com/alph4b3th/rakstar/utils"
)

type icon struct {
	x, y, z    float32
	marketType int
	color      int
	style      int
}

var (
	// playerIcons[playerID][slotID]icon
	playerIcons = make(map[int]map[int]icon)
	mu          sync.RWMutex
)

func init() {
	tick := time.NewTicker(time.Second)
	go updateMapIcon(tick)
}

func updateMapIcon(tick *time.Ticker) {
	for range tick.C {
		mu.RLock()
		for playerId, icons := range playerIcons {
			var isConnected bool
			Builder().Select(playerId).Connected(&isConnected)
			if !isConnected {
				continue
			}

			px, py, pz, _, err := Builder().Select(playerId).Coordinate() //obtem coordenadas
			if err != nil {
				continue
			}

			for slotId, ic := range icons {
				distanceRender := utils.CalculateDistance(px, py, pz, ic.x, ic.y, ic.z) //calcula distancia entre jogador e icones

				if distanceRender < 200.0 {
					natives.SetPlayerMapIcon(playerId, slotId, ic.x, ic.y, ic.z, ic.marketType, ic.color, ic.style)
				} else {
					natives.RemovePlayerMapIcon(playerId, slotId)
				}
			}
		}
		mu.RUnlock()
	}
}

func (pb *PlayerBuilder) MapIcon(x, y, z float32, marketType, color, style int) int {
	mu.Lock()
	defer mu.Unlock()

	if _, ok := playerIcons[pb.ID]; !ok {
		playerIcons[pb.ID] = make(map[int]icon)
	}

	slotId := -1
	for i := 0; i < 100; i++ {
		if _, occupied := playerIcons[pb.ID][i]; !occupied {
			slotId = i
			break
		}
	}

	if slotId != -1 {
		playerIcons[pb.ID][slotId] = icon{x, y, z, marketType, color, style}
	}

	return slotId 
}

func (pb *PlayerBuilder) RemoveMapIcon(slotId int) *PlayerBuilder {
	mu.Lock()
	defer mu.Unlock()

	if icons, ok := playerIcons[pb.ID]; ok {
		delete(icons, slotId)
		natives.RemovePlayerMapIcon(pb.ID, slotId)
	}
	return pb
}
