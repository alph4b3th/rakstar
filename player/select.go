package player

import (
	"github.com/alph4b3th/rakstar/internal/natives"
	"github.com/alph4b3th/rakstar/utils"
)

func (pb *PlayerBuilder) Color(color int) *PlayerBuilder {
	natives.SetPlayerColor(pb.ID, color)
	return pb
}

// Select é um operador lógico que seleciona um jogador com base em um apelido ou ID
// fornecido.
// Ele recebe um argumento que pode ser uma string (representando o apelido do jogador)
// ou um inteiro (representando o ID do jogador).
// Se o argumento for uma string, o método percorrerá todos os jogadores e comparará
// o apelido de cada jogador com a string fornecida.
// Se encontrar um jogador cujo apelido corresponda à string, ele definirá o campo ID
// do objeto PlayerBuilder para o ID desse jogador.
// Se o argumento for um inteiro, o método simplesmente definirá o campo ID do objeto
// PlayerBuilder para esse inteiro.
func (pb *PlayerBuilder) Select(arg interface{}) *PlayerBuilder {
	pb.ID = utils.SelectPlayer(arg)
	return pb
}
