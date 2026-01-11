package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerEnterCheckpoint", HandlerOnPlayerEnterCheckpoint)
}

func HandlerOnPlayerEnterCheckpoint(playerid natives.Player) bool {
	if handler, ok := events["playerEnterCheckpoint"].(func(int) bool); ok {
		fmt.Printf("o jogador entrou em algum checkpoint: %v\n", playerid)
		return handler(playerid.ID)
	}

	return true
}
