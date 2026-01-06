package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerText", HandlerOnPlayerText)
}

func HandlerOnPlayerText(playerid natives.Player, text string) bool {
	if handler, ok := events["playerText"].(func(int, string) bool); ok {
		fmt.Printf("O jogador disse no chat algo. ID: %v\n", playerid)
		return handler(playerid.ID, text)
	}

	return true
}
