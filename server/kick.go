package server

import (
	"time"

	"github.com/alph4b3th/rakstar/internal/natives"
)

func (rb *ServerBuild) Player(playerid int) *ServerBuild {
	rb.playerID = playerid
	return rb
}

func (rb *ServerBuild) Wait(wait ...time.Duration) *ServerBuild {
	if wait[0].Seconds() < 1 {
		wait[0] = time.Second
	}
	time.Sleep(wait[0])
	return rb
}

func (rb *ServerBuild) Expulse() *ServerBuild {
	if rb.playerID == -1 {
		return rb
	}

	natives.Kick(rb.playerID)

	return rb
}
