package server

import (
	"fmt"
	"time"

	"github.com/alph4b3th/rakstar/chat"
	"github.com/alph4b3th/rakstar/internal/natives"
)

/*
Define a mensagem que será enviada durante a contagem regresiva para reiniciar

Exemplo: "O servidor reiniciará"

# # Resultado:
  - O servidor reiniciará - 5
  - O servidor reiniciará - 4
  - O servidor reiniciará - 3
  - O servidor reiniciará - 2
  - O servidor reiniciará - 1
  - O servidor reiniciará - 0
*/
func (sb *ServerBuild) MessageLoop(msg string) *ServerBuild {
	sb.msgLoop = msg
	return sb
}

/*
Efetiva a ordem de reinício, recebendo um objeto builder

# # Exemplo:

cb := chat.Build()

cb.PlayerID(chat.global).
Tag("servidor").
Color(common.WarnColorStr).
Message("ordem de reinício")

server.
Build().
MessageLoop("O servidor reiniciará").
RestartNow(cb)

# * Resultado do chat:
  - [SERVIDOR] ordem de reínicio
  - [SERVIDOR] o servidor reiniciará - 5
  - [SERVIDOR] o servidor reiniciará - 4
  - [SERVIDOR] o servidor reiniciará - 3
  - [SERVIDOR] o servidor reiniciará - 2
  - [SERVIDOR] o servidor reiniciará - 1
  - [SERVIDOR] o servidor reiniciará - 0

... servidor reiniciou
*/
func (sb *ServerBuild) RestartNow(cb *chat.ChatBuilder) *ServerBuild {
	if cb != nil {
		cb.Send()
	}
	if sb.msgLoop == "" {
		sb.msgLoop = "o servidor reiniciará"
	}

	time.Sleep(7 * time.Second)
	for i := 5; i > 0; i-- {
		time.Sleep(time.Second)
		cb.
			Range(chat.Global).
			Message(fmt.
				Sprintf("%v - %v", sb.msgLoop, i)).
			Send()
	}

	natives.SendRconCommand("gmx")
	return sb
}
