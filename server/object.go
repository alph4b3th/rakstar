package server

import (
	"math"
	"time"

	"github.com/alph4b3th/rakstar/internal/natives"
)

func (sb *ServerBuild) CreateObect(modelid int, x float32, y float32, z float32, rX float32, rY float32, rZ float32, DrawDistance float32) int {

	id := natives.CreateObject(modelid, x, y, z, rX, rY, rZ, DrawDistance)
	return id
}

func (sb *ServerBuild) Move(objectID int, x float32, y float32, z float32, speed, rX float32, rY float32, rZ float32) *ServerBuild {

	natives.MoveObject(objectID, x, y, z, speed, rX, rY, rZ)
	return sb
}

func (sb *ServerBuild) SetObectPos(objectID int, x float32, y float32, z float32) *ServerBuild {

	natives.SetObjectPos(objectID, x, y, z)
	return sb
}

func (sb *ServerBuild) MoveObjectSmooth(
	objectID int,
	from, to Vector3,
	duration float64,
	reverse bool,
) *ServerBuild {

	go func() {

		step := 0.05
		elapsed := 0.0

		for elapsed <= duration {
			t := elapsed / duration

			if reverse {
				t = 1 - t
			}

			f := sigmoidEase(t)

			pos := Vector3{
				X: from.X + (to.X-from.X)*f,
				Y: from.Y + (to.Y-from.Y)*f,
				Z: from.Z + (to.Z-from.Z)*f,
			}

			// runtime.Gosched()
			natives.SetObjectPos(
				objectID,
				float32(pos.X),
				float32(pos.Y),
				float32(pos.Z),
			)

			time.Sleep(time.Millisecond * 30)
			elapsed += step
		}

		if reverse {
			natives.SetObjectPos(objectID,
				float32(from.X), float32(from.Y), float32(from.Z))
		} else {
			natives.SetObjectPos(objectID,
				float32(to.X), float32(to.Y), float32(to.Z))
		}
	}()
	return sb
}

type Vector3 struct {
	X, Y, Z float64
}

func sigmoidEase(t float64) float64 {
	x := (t * 12) - 6
	return 1 / (1 + math.Exp(-x))
}
