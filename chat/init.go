package chat

import (
	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
	"github.com/alph4b3th/rakstar/internal/utils/common"
)

func init() {
	callbacks.On("playerText", handlerChat)
}

func handlerChat(p natives.Player, text string) bool {
	Builder().
		DisableEncodding().
		Message(text).
		Select(p.ID).
		Range(Local).
		Color(common.ChatLocalColorStr).
		Tag("local").
		Send()

	return false
}
