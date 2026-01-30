package utils

import "math"

// CalculateSpeedFromVelocity estima a velocidade
// usando a velocidade de três eixos.
//
// Útil para estimar a velocidade de um veículo.
func CalculateSpeedFromVelocity(vx, vy, vz float32) float32 {
	return float32(math.Sqrt(
		float64(vx*vx + vy*vy + vz*vz),
	))
}
