package server

import "github.com/alph4b3th/rakstar/internal/natives"

func (sb *ServerBuild) GivePlayerMoney(playerid, money int) *ServerBuild {
	natives.GivePlayerMoney(playerid, money)
	return sb
}

func (sb *ServerBuild) ResetPlayerMoney(playerid int) *ServerBuild {
	natives.ResetPlayerMoney(playerid)
	return sb
}
