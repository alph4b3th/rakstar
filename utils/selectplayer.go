package utils

import (
	"github.com/alph4b3th/rakstar/internal/natives"
	"github.com/alph4b3th/rakstar/internal/utils/constants/playerConst"
)

// SelectPlayer resolve um jogador a partir do argumento informado.
//
// O comportamento depende do tipo de `arg`:
//   - string: interpreta como nickname e percorre os jogadores conectados,
//     retornando o playerID do primeiro nome que corresponder exatamente.
//   - int: interpreta como playerID e o retorna diretamente.
//
// Retorna -1 caso o jogador não seja encontrado ou o tipo do argumento
// não seja suportado.
func SelectPlayer(arg interface{}) int {

	switch v := arg.(type) {
	case string:
		var name string
		for i := 0; i < playerConst.MaxPlayers; i++ {
			natives.GetPlayerName(i, &name, playerConst.MaxPlayerName)
			if name == v {
				return i
			}

		}
	case int:
		return v

	}
	return -1
}
