package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerEnterRaceCheckpoint", HandlerOnPlayerEnterRaceCheckpoint)
}

func HandlerOnPlayerEnterRaceCheckpoint(playerid natives.Player) bool {
	if handler, ok := events["playerEnterRaceCheckpoint"].(func(int) bool); ok {
		fmt.Println("O player entrou em checkpoit de corrida. ID:", playerid)
		return handler(playerid.ID)
	}

	return true
}
