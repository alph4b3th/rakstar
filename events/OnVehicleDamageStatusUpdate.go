package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("vehicleDamageStatusUpdate", HandlerOnVehicleDamageStatusUpdate)
}

func HandlerOnVehicleDamageStatusUpdate(vehicleid int, playerid natives.Player) bool {
	if handler, ok := events["vehicleDamageStatusUpdate"].(func(int, int) bool); ok {
		fmt.Println("O veiculo sofreu danos. ID:", vehicleid)
		return handler(vehicleid, playerid.ID)
	}

	return true
}
