package server

import "github.com/alph4b3th/rakstar/internal/natives"

func (rb *ServerBuild) GivePlayerMoney(playerid, money int) *ServerBuild {
	natives.GivePlayerMoney(playerid, money)
	return rb
}

func (rb *ServerBuild) ResetPlayerMoney(playerid int) *ServerBuild {
	natives.ResetPlayerMoney(playerid)
	return rb
}

