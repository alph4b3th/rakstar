package server

import "math"

//calculateDistance obtem a distância entre dois pontos.
//Útil em cenários como:
//
// - Obter a distância entre um veículo e um jogador
//
// - Obter a distância entre dois veículos
//
// - Obter a distância entre dois jogadores
//
//A equipe do rakstar, recomenda a utilização desta função em vez
//de utilizar funções nativas do samp.
func CalculateDistance(x, y, z, x2, y2, z2 float32) float32 {
	dx := x2 - x
	dy := y2 - y
	dz := z2 - z
	return float32(math.Sqrt(float64(dx*dx + dy*dy + dz*dz)))
}
