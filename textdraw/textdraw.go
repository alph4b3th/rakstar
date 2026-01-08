package textdraw

import "github.com/alph4b3th/rakstar/internal/natives"

func (td *TextDrawBuilder) Text(text string) *TextDrawBuilder {
	td.text = text
	return td
}

func (td *TextDrawBuilder) SetPos(x, y float32) *TextDrawBuilder {
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
