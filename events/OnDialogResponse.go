package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/dialog"
	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("dialogResponse", HandlerOnDialogResponse)
}

func HandlerOnDialogResponse(playerid natives.Player, dialogid, response, listitem int, text string) bool {

	dialog.HandleDialogResponse(playerid.ID, dialogid, response, listitem, text)
	if handler, ok := events["dialogResponse"].(func(int, int, int, int, string) bool); ok {
		fmt.Println("O jogador respondeu uma dialog. ID:", playerid)
		return handler(playerid.ID, dialogid, response, listitem, text)
	}

	return true
}
