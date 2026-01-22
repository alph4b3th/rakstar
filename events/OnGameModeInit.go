package events

import (
	"github.com/alph4b3th/rakstar/internal/callbacks"
)

func init() {
	callbacks.On("goModeInit", HandlerOnGameModeInit)
}

func HandlerOnGameModeInit() bool {

	if handler, ok := events["goModeInit"].(func() bool); ok {
		return handler()
	}

	return true
}
