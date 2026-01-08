package textdraw

import (
	"fmt"

	"github.com/alph4b3th/rakstar/internal/natives"
	"github.com/alph4b3th/rakstar/player"
)

func (td *TextDrawBuilder) Text(text string) *TextDrawBuilder {
	td.text = text
	return td
}

func (td *TextDrawBuilder) Pos(x, y float32) *TextDrawBuilder {
	td.x, td.y = x, y
	return td
}

func (td *TextDrawBuilder) Create() *TextDrawBuilder {
	td.id = natives.TextDrawCreate(td.x, td.y, td.text)
	return td
}

func (td *TextDrawBuilder) Alignment(alignment int) *TextDrawBuilder {
	td.alignment = alignment
	natives.TextDrawAlignment(td.id, alignment)

	return td
}

func (td *TextDrawBuilder) BackgroudColor(color int) *TextDrawBuilder {

	td.backgroundColor = color
	natives.TextDrawBackgroundColor(td.id, color)

	return td
}

func (td *TextDrawBuilder) Font(font int) *TextDrawBuilder {

	td.font = font

	natives.TextDrawFont(td.id, font)

	return td
}

func (td *TextDrawBuilder) LetterSize(width, height float32) *TextDrawBuilder {

	td.width, td.height = width, height

	natives.TextDrawLetterSize(td.id, width, height)
	return td
}

func (td *TextDrawBuilder) Color(color int) *TextDrawBuilder {

	td.color = color
	natives.TextDrawColor(td.id, td.color)

	return td
}

func (td *TextDrawBuilder) Outline(size int) *TextDrawBuilder {

	td.size = size
	natives.TextDrawSetOutline(td.id, size)
	return td
}

func (td *TextDrawBuilder) Proportional(proportional bool) *TextDrawBuilder {
	td.proportional = proportional
	natives.TextDrawSetProportional(td.id, proportional)
	return td
}

func (td *TextDrawBuilder) Shadow(size int) *TextDrawBuilder {
	td.shadowSize = size
	natives.TextDrawSetShadow(td.id, size)
	return td
}

func (td *TextDrawBuilder) UseBox(use bool) *TextDrawBuilder {

	td.useBox = use
	natives.TextDrawUseBox(td.id, use)
	return td
}

func (td *TextDrawBuilder) BoxColor(color int) *TextDrawBuilder {
	td.boxColor = color
	natives.TextDrawBoxColor(td.id, color)
	return td
}

func (td *TextDrawBuilder) TextSize(width, height float32) *TextDrawBuilder {
	td.textSizeW, td.textSizeH = width, height
	natives.TextDrawTextSize(td.id, width, height)
	return td
}

func (td *TextDrawBuilder) ShowPlayer(player *player.PlayerBuilder) {
	natives.TextDrawShowForPlayer(player.ID, td.id)
}

func (td *TextDrawBuilder) HidePlayer(player *player.PlayerBuilder) {
	fmt.Println("[textdraw] escondendo para: ", player.ID, "a textdraw: ", td.id)
	natives.TextDrawHideForPlayer(player.ID, td.id)
}

func (td *TextDrawBuilder) UpdateText(player *player.PlayerBuilder) {
	natives.TextDrawSetString(td.id, td.text)
}
