package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("playerEnterVehicle", HandlerOnPlayerEnterVehicle)
}

func HandlerOnPlayerEnterVehicle(playerid natives.Player, vehicleid int, ispassager bool) bool {
	if handler, ok := events["playerEnterVehicle"].(func(int, int, bool) bool); ok {
		fmt.Println("O player entrou no veiculo. ID:", playerid)
		return handler(playerid.ID, vehicleid, ispassager)
	}

	return true
}
