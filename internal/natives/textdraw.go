package natives

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/utils/constants/textDrawConst"
)

const (
	FontSanAndreas = iota
	FontClear
	FontCapitalClear
	FontGTA
	FontSprite
)

type PlayerTextDraw struct {
	player   *Player
	textDraw int
	align    int
}

func (p *Player) NewTextDraw(x, y float32, text string) (PlayerTextDraw, error) {
	mu.Lock()
	defer mu.Unlock()

	td := PlayerTextDraw{player: p, textDraw: CreatePlayerTextDraw(p.ID, x, y, text)}
	if td.textDraw == textDrawConst.InvalidTextDraw {
		return td, fmt.Errorf("invalid playertextdraw")
	}
	return td, nil
}

func (p *PlayerTextDraw) Destroy() {
	mu.Lock()
	defer mu.Unlock()

	PlayerTextDrawDestroy(p.player.ID, p.textDraw)
}

func (p *PlayerTextDraw) SetString(text string) {
	mu.Lock()
	defer mu.Unlock()

	PlayerTextDrawSetString(p.player.ID, p.textDraw, text)
}

func (p *PlayerTextDraw) Show() {
	mu.Lock()
	defer mu.Unlock()

	PlayerTextDrawShow(p.player.ID, p.textDraw)
}

func (p *PlayerTextDraw) Hide() {
	mu.Lock()
	defer mu.Unlock()

	PlayerTextDrawHide(p.player.ID, p.textDraw)
}

func (p *PlayerTextDraw) Font(font int) {
	mu.Lock()
	defer mu.Unlock()

	PlayerTextDrawFont(p.player.ID, p.textDraw, font)
}

func (p *PlayerTextDraw) UseBox(use bool) {
	mu.Lock()
	defer mu.Unlock()

	PlayerTextDrawUseBox(p.player.ID, p.textDraw, use)
}

func (p *PlayerTextDraw) SetAlignment(align int) {
	mu.Lock()
	defer mu.Unlock()

	p.align = align
	PlayerTextDrawAlignment(p.player.ID, p.textDraw, p.align)
}

func (p *PlayerTextDraw) SetTextSize(x, y float32) {
	mu.Lock()
	defer mu.Unlock()

	if p.align == 2 {
		x, y = y, x
	}
	PlayerTextDrawTextSize(p.player.ID, p.textDraw, x, y)
}

func (p *PlayerTextDraw) SetColor(color int) {
	mu.Lock()
	defer mu.Unlock()

	PlayerTextDrawColor(p.player.ID, p.textDraw, color)
}

var SetColour = (*PlayerTextDraw).SetColor

func (p *PlayerTextDraw) SetBoxColor(color int) {
	mu.Lock()
	defer mu.Unlock()

	PlayerTextDrawBoxColor(p.player.ID, p.textDraw, color)
}

var SetBoxColour = (*PlayerTextDraw).SetBoxColor

func (p *PlayerTextDraw) SetBackgroundColor(color int) {
	mu.Lock()
	defer mu.Unlock()

	PlayerTextDrawBackgroundColor(p.player.ID, p.textDraw, color)
}

var SetBackgroundColour = (*PlayerTextDraw).SetBackgroundColor
