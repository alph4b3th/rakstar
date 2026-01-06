package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerInteriorChange", HandlerOnPlayerInteriorChange)
}

func HandlerOnPlayerInteriorChange(playerid natives.Player, newinterior, oldinterior int) bool {
	if handler, ok := events["playerInteriorChange"].(func(int, int, int) bool); ok {
		fmt.Println("O player mudou de interior. ID:", playerid)
		return handler(playerid.ID, newinterior, oldinterior)
	}

	return true
}
