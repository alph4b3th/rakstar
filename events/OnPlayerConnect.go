package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerConnect", HandlerOnPlayerConnect)
}

func HandlerOnPlayerConnect(playerid natives.Player) bool {
	if handler, ok := events["playerConnect"].(func(int) bool); ok {
		fmt.Println("O jogador se conectou. ID:", playerid)
		return handler(playerid.ID)
	}

	return true
}
