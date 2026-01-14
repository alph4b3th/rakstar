package utils

import "math"

func CalculateDistance(x, y, z, x2, y2, z2 float32) float32 {
	dx := x2 - x
	dy := y2 - y
	dz := z2 - z
	return float32(math.Sqrt(float64(dx*dx + dy*dy + dz*dz)))
}
