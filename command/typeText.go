package command

const (
	MustBeUppercase = iota
	MustBeLowercase
	MustHavePrefix
	MustHaveSufix
	MustCompileRegex
)

type TypeText struct {
	c *conditionalsBuilder
}

// TypeText define o tipo lógico do parâmetro para o tipo Text
func (c *conditionalsBuilder) TypeText() *TypeText {
	c.typeIdx = typeText
	tText := new(TypeText)
	tText.c = c
	return tText
}

// MustBeUppercase é válido se o texto estiver em caixa alta.
// Caso contrário o comando falhará
func (t *TypeText) MustBeUppercase() *TypeText {
	t.c.createConditional(MustBeUppercase, t.c.typeIdx, nil)
	return t
}

// MustBeLowercase é válido se o texto estiver em caixa baixa.
// Caso contrário o comando falhará
func (t *TypeText) MustBeLowercase() *TypeText {
	t.c.createConditional(MustBeLowercase, t.c.typeIdx, nil)
	return t
}

// MustHavePrefix compara o prefix com o início do parâmetro.
// Se iguais, é válido. Caso contrário, o comando falhará
func (t *TypeText) MustHavePrefix(prefix string) *TypeText {
	t.c.createConditional(MustHavePrefix, t.c.typeIdx, prefix)
	return t
}

// MustHaveSufix compara o sufix com o fim do parâmetro.
// Se iguais, é válido. Caso contrário, o comando falhará
func (t *TypeText) MustHaveSufix(sufix string) *TypeText {
	t.c.createConditional(MustHaveSufix, t.c.typeIdx, sufix)
	return t
}

// MustCompileRegex verifica se o parâmetro corresponde ao regex.
// Se corresponder, é válido. Caso contrário, o comando falhará
func (t *TypeText) MustCompileRegex(regex string) *TypeText {
	t.c.createConditional(MustCompileRegex, t.c.typeIdx, regex)
	return t
}

// End encerra a expressão lógica
func (t *TypeText) End() *conditionalsBuilder {
	t.c.Set()
	return t.c
}
