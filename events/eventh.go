package events

import (
	"github.com/alph4b3th/rakstar/internal/callbacks"
)

type Event struct {
	handler interface{}
	event   string
}

func NewEvent() *Event {
	return new(Event)
}

func (e *Event) SetEvent(event string) {
	e.event = event
}

func (e *Event) SetHandler(handler interface{}) {
	e.handler = handler
}

func (e *Event) Subscribe() error {
	err := callbacks.On(e.event, e.handler)
	return err
}
