package server

import "github.com/alph4b3th/rakstar/internal/natives"

func (sb *ServerBuild) CreatePickup(model, Type int, x, y, z float32, world int) int {
	return natives.CreatePickup(model, Type, x, y, z, world)
}

func (sb *ServerBuild) DestroyPickup(pickupId int) *ServerBuild {
	natives.DestroyPickup(pickupId)
	return sb
}
