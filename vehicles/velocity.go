package vehicles

import (
	"github.com/alph4b3th/rakstar/events"
	"github.com/alph4b3th/rakstar/internal/natives"
	"github.com/alph4b3th/rakstar/player"
	"github.com/alph4b3th/rakstar/server"
)

var VelocityLimters map[int]limiter

type limiter struct {
	max      float32
	playerId int
	builder  *vehicleBuilder
}

func init() {
	VelocityLimters = make(map[int]limiter)
	// event := events.NewEvent()
	// event.SetHandler(Tick)
	// event.SetEvent("playerUpdate")
	// event.Subscribe()

	event2 := events.NewEvent()
	event2.SetEvent("playerUpdate")
	event2.SetHandler(Tick)
	event2.Subscribe()

}

func Tick(id int) bool {
	go func() {
		for _, limiter := range VelocityLimters {
			var x, y, z float32
			var vx, vy, vz float32

			if !natives.GetVehiclePos(limiter.builder.id, &x, &y, &z) {
				return
			}

			if !natives.GetVehicleVelocity(limiter.builder.id, &vx, &vy, &vz) {
				return
			}

			px, py, pz, _, err := player.Builder().Select(limiter.playerId).Coordinate()
			if err != nil {
				return
			}

			nx := x + vx
			ny := y + vy
			nz := z + vz

			distance := server.CalculateDistance(px, py, pz, nx, ny, nz)

			if distance <= limiter.max || distance == 0 {
				return
			}

			scale := limiter.max / distance

			natives.SetVehicleVelocity(
				limiter.builder.id,
				vx*scale,
				vy*scale,
				vz*scale,
			)
		}
	}()
	return true
}
