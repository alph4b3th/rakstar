package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerExitVehicle", HandlerOnPlayerExitVehicle)
}

func HandlerOnPlayerExitVehicle(playerid natives.Player, vehicleid int) bool {
	if handler, ok := events["playerExitVehicle"].(func(int, int) bool); ok {
		fmt.Println("O player saiu do veiculo. ID:", playerid)
		return handler(playerid.ID, vehicleid)
	}

	return true
}
