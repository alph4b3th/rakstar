package events

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/callbacks"
)

func init() {
	callbacks.On("vehicleSpawn", HandlerOnVehicleSpawn)
}

func HandlerOnVehicleSpawn(vehicleid int) bool {
	if handler, ok := events["vehicleSpawn"].(func(int) bool); ok {
		fmt.Println("O veiculo spawnou. ID:", vehicleid)
		return handler(vehicleid)
	}

	return true
}
