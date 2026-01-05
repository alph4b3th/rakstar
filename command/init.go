package command

import (
	"github.com/alph4b3th/rakstar/chat"
	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/utils/common"
)

func init() {
	chat := chat.Builder()
	chat.Color(common.WarnColorStr).
		Message("Nenhum comando foi encontrado")
	SetConfig(chat, "Comando errado, similar")

	err := callbacks.On("playerCommandText", HandlePlayerCommandText)
	panic(err)
}
