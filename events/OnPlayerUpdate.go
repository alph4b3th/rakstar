package events

import (
	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerUpdate", HandlerOnPlayerUpdate)
}

func HandlerOnPlayerUpdate(playerid natives.Player) bool {
	if handler, ok := events["playerUpdate"].(func(int) bool); ok {
		return handler(playerid.ID)
	}

	return false
}
