package server

import "github.com/alph4b3th/rakstar/internal/natives"

func (sb *ServerBuild) SetPlayerCheckpoint(playerid int, x, y, z, size float32) *ServerBuild {
	natives.SetPlayerCheckpoint(playerid, x, y, z, size)
	return sb
}

func (sb *ServerBuild) DisablePlayerCheckpoint(playerid int) *ServerBuild {
	natives.DisablePlayerCheckpoint(playerid)
	return sb
}
