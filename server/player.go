package server

import (
	"errors"

	"github.com/alph4b3th/rakstar/chat"
	"github.com/alph4b3th/rakstar/internal/natives"
	"github.com/alph4b3th/rakstar/player"
)

var (
	ErrFailureGetIp = errors.New("Failure to obtain player's IP address.")
)

func (rb *ServerBuild) Spawn(cb *chat.ChatBuilder) *ServerBuild {

	if cb != nil {
		cb.Send()
	}
	natives.SpawnPlayer(rb.playerID)
	return rb
}

// Invocar esta função retornará o IP do jogador
func (rb *ServerBuild) GetIP(player player.PlayerBuilder) (string, error) {
	var ip string
	sucess := natives.GetPlayerIp(player.ID, &ip, 16)
	if !sucess {
		return "", ErrFailureGetIp
	}
	return ip, nil
}

func (rb *ServerBuild) UsePlayerPedAnims() *ServerBuild {

	natives.UsePlayerPedAnims()
	return rb
}
