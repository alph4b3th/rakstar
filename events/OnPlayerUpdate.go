package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerUpdate", HandlerOnPlayerUpdate)
}

func HandlerOnPlayerUpdate(playerid natives.Player) bool {
	if handler, ok := events["playerUpdate"].(func(int) bool); ok {
		fmt.Printf("O jogador atualizou. ID: %v\n", playerid)
		return handler(playerid.ID)
	}

	return false
}
