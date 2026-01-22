package server

import (
	"github.com/alph4b3th/rakstar/internal/natives"
)

func (sb *ServerBuild) CreateObect(modelid int, x float32, y float32, z float32, rX float32, rY float32, rZ float32, DrawDistance float32) int {

	id := natives.CreateObject(modelid, x, y, z, rX, rY, rZ, DrawDistance)
	return id
}

func (sb *ServerBuild) Move(objectID int, x float32, y float32, z float32, speed, rX float32, rY float32, rZ float32) *ServerBuild {

	natives.MoveObject(objectID, x, y, z, speed, rX, rY, rZ)
	return sb
}
