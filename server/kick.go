package server

import (
	"time"

	"github.com/alph4b3th/rakstar/chat"
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

func (rb *ServerBuild) Expulse(cb *chat.ChatBuilder) *ServerBuild {
	if rb.playerID == -1 {
		return rb
	}
	if cb != nil {
		cb.Send()
	}

	natives.Kick(rb.playerID)

	return rb
}
