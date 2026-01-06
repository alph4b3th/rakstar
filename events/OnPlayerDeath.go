package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerDeath", HandlerOnPlayerDeath)
}

func HandlerOnPlayerDeath(playerid natives.Player, killerid natives.Player, reason int) bool {
	if handler, ok := events["playerDeath"].(func(int, int, int) bool); ok {
		fmt.Printf("O jogador %v foi morto. Matador: %v, razão: %v\n", playerid, killerid, reason)
		return handler(playerid.ID, killerid.ID, reason)
	}

	return true
}
