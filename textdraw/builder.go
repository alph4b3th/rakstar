package textdraw

type TextDrawBuilder struct {
	id              int
	text            string
	font            int
	width, height float32
	x, y            float32
	alignment       int
	backgroundColor int
}

func Builder() *TextDrawBuilder {
	return new(TextDrawBuilder)
}
