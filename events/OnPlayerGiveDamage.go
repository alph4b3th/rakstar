package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerGiveDamage", HandlerOnPlayerGiveDamage)
}

func HandlerOnPlayerGiveDamage(playerid natives.Player, damagedid int, amount float32, weapon, bodypart int) bool {
	if handler, ok := events["playerGiveDamage"].(func(int, int, float32, int, int) bool); ok {
		fmt.Println("O player atacou alguém. ID:", playerid)
		return handler(playerid.ID, damagedid, amount, weapon, bodypart)
	}

	return true
}
