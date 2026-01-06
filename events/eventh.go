package events

type Event struct {
	handler interface{}
	event   string
}

var events map[string]any

func init() {
	events = make(map[string]any)

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

func (e *Event) Subscribe() {
	events[e.event] = e.handler

}
