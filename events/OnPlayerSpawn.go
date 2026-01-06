package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerSpawn", HandlerOnPlayerSpawn)
}

func HandlerOnPlayerSpawn(playerid natives.Player) bool {
	if handler, ok := events["playerSpawn"].(func(int) bool); ok {
		fmt.Printf("O jogador spawnou no mapa. ID: %v\n", playerid)
		return handler(playerid.ID)
	}

	return true
}
