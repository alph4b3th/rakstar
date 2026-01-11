package server

import "github.com/alph4b3th/rakstar/internal/natives"

func (rb *ServerBuild) SetPlayerCheckpoint(playerid int, x, y, z, size float32) *ServerBuild {
	natives.SetPlayerCheckpoint(playerid, x, y, z, size)
	return rb
}

func (rb *ServerBuild) DisablePlayerCheckpoint(playerid int) *ServerBuild {
	natives.DisablePlayerCheckpoint(playerid)
	return rb
}
