package server

import (
	"time"

	"github.com/alph4b3th/rakstar/internal/natives"
)

func (sb *ServerBuild) Player(playerid int) *ServerBuild {
	sb.playerID = playerid
	return sb
}

func (sb *ServerBuild) Wait(wait ...time.Duration) *ServerBuild {
	if wait[0].Seconds() < 1 {
		wait[0] = time.Second
	}
	time.Sleep(wait[0])
	return sb
}

func (sb *ServerBuild) Expulse() *ServerBuild {
	if sb.playerID == -1 {
		return sb
	}

	natives.Kick(sb.playerID)

	return sb
}
