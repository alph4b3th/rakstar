package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerLeaveRaceCheckpoint", HandlerOnPlayerLeaveRaceCheckpoint)
}

func HandlerOnPlayerLeaveRaceCheckpoint(playerid natives.Player) bool {
	if handler, ok := events["playerLeaveRaceCheckpoint"].(func(int) bool); ok {
		fmt.Println("O player saiu em checkpoit de corrida. ID:", playerid)
		return handler(playerid.ID)
	}

	return true
}
