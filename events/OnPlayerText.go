package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/chat"
	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
	"github.com/alph4b3th/rakstar/internal/utils/common"
)

func init() {
	callbacks.On("playerText", HandlerOnPlayerText)
}

func HandlerOnPlayerText(playerid natives.Player, text string) bool {
	if handler, ok := events["playerText"].(func(int, string) bool); ok {
		fmt.Printf("O jogador disse no chat algo. ID: %v\n", playerid)
		return handler(playerid.ID, text)
	}

	fmt.Println("chatlocal:", text)
	chat.Builder().
		DisableEncodding().
		Message(text).
		Select(playerid.ID).
		Range(chat.Local).
		// WithName().
		Color(common.ChatLocalColorStr).
		Tag("local").
		Send()
	return false
}
