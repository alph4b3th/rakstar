package server

import "github.com/alph4b3th/rakstar/internal/natives"

func (sb *ServerBuild) DisableInteriorEnterExits() *ServerBuild {
	natives.DisableInteriorEnterExits()
	return sb
}
