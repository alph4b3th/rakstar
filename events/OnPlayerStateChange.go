package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerStateChange", HandlerOnPlayerStateChange)
}

func HandlerOnPlayerStateChange(playerid natives.Player, newstate, oldstate int) bool {
	if handler, ok := events["playerStateChange"].(func(int, int, int) bool); ok {
		fmt.Println("O player mudou de estado. ID:", playerid)
		return handler(playerid.ID, newstate, oldstate)
	}

	return true
}
