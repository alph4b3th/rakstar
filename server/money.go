package server

import "github.com/alph4b3th/rakstar/internal/natives"

func (rb *ServerBuild) GivePlayerMoney(playerid, money int) *ServerBuild {
	natives.GivePlayerMoney(playerid, money)
	return rb
}
