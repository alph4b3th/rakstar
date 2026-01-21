package player

import "github.com/alph4b3th/rakstar/internal/natives"

func (pb *PlayerBuilder) LevelStars(stars int) *PlayerBuilder {

	natives.SetPlayerWantedLevel(pb.ID, stars)
	
	return pb
}
