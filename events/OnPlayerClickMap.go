package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerClickMap", HandlerOnPlayerClickMap)
}

func HandlerOnPlayerClickMap(playerid natives.Player, fx, fy, fz float32) bool {
	if handler, ok := events["playerClickMap"].(func(int, float32, float32, float32) bool); ok {
		fmt.Printf("O jogador clicou no mapa. (%v, %v, %v) ID: %v\n", fx, fy, fz, playerid)
		return handler(playerid.ID, fx, fy, fz)
	}

	return true
}
