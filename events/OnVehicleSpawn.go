package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
	"github.com/alph4b3th/rakstar/internal/natives"
)

func init() {
	callbacks.On("vehicleRespray", HandlerOnVehicleRespray)
}

func HandlerOnVehicleRespray(playerid natives.Player, vehicleid, color1, color2	 int) bool {
	if handler, ok := events["vehicleRespray"].(func(int, int, int) bool); ok {
		fmt.Println("O veiculo mudou de cor. ID:", vehicleid)
		return handler(vehicleid, color1, color2)
	}

	return true
}
