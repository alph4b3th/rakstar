package ui

import (
	"errors"

	"github.com/alph4b3th/rakstar/player"
)

type directionBar uint

const (
	BAR_DIRECTION_RIGHT = iota
	BAR_DIRECTION_LEFT
	BAR_DIRECTION_HORIZONTAL_FROM_0
	BAR_DIRECTION_UP
	BAR_DIRECTION_DOWN
	BAR_DIRECTION_VERTICAL_FROM_0
)

var (
	InvalidPlayerError = errors.New("attempt to create player progress bar for invalid player")
)

type progressBar struct {
	direction                 uint
	isCreated                 bool
	show                      bool
	posX, posY, posZ          float32
	width, height             float32
	color                     int
	minValue, value, maxValue float32
	paddingX, paddingY        float32
}

func (ui *UserInterface) CreateProgressBar(
	x, y, z float32,
	width, height float32,
	color int,
	maxValue float32,
	direction uint,
) error {
	var pOnline bool
	player.Builder().Select(ui.pID).Connected(&pOnline)

	if !pOnline {
		return InvalidPlayerError
	}

	ui.progressBar.direction = direction

	ui.progressBar.color = color

	ui.progressBar.height = height
	ui.progressBar.width = width

	ui.progressBar.maxValue = maxValue
	ui.progressBar.minValue = 0
	ui.progressBar.value = 0

	ui.progressBar.paddingX = 1.2
	ui.progressBar.paddingY = 1.0

	ui.progressBar.show = true
	ui.progressBar.isCreated = true

	ui.progressBar.posX = x
	ui.progressBar.posY = y
	ui.progressBar.posZ = z
	
	return nil
}
