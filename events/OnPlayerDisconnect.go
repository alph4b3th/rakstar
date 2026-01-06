package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerDisconnect", HandlerOnPlayerDisconnect)
}

func HandlerOnPlayerDisconnect(playerid natives.Player, reason int) bool {
	if handler, ok := events["playerDisconnect"].(func(int, int)); ok {
		handler(playerid.ID, reason)
	}

	fmt.Println("O jogador se desconectou. ID:", playerid)
	return true
}
