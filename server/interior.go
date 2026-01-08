package server

import "github.com/alph4b3th/rakstar/internal/natives"

func (rb *ServerBuild) DisableInteriorEnterExits() *ServerBuild {
	natives.DisableInteriorEnterExits()
	return rb
}
