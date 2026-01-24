package progressbar2

import (
	"errors"
	"math"

	"github.com/alph4b3th/rakstar/internal/natives"
	"github.com/alph4b3th/rakstar/player"
)

type directionBar uint

const (
	BAR_DIRECTION_RIGHT directionBar = iota
	BAR_DIRECTION_LEFT
	BAR_DIRECTION_HORIZONTAL_FROM_0
	BAR_DIRECTION_UP
	BAR_DIRECTION_DOWN
	BAR_DIRECTION_VERTICAL_FROM_0
)

const (
	E_PBAR_BACKGROUND_POS_X = iota
	E_PBAR_BACKGROUND_POS_Y
	E_PBAR_BACKGROUND_RIGHT
	E_PBAR_BACKGROUND_HEIGHT
	E_PBAR_FILLER_POS_X
	E_PBAR_FILLER_POS_Y
	E_PBAR_FILLER_RIGHT
	E_PBAR_FILLER_HEIGHT
	E_PBAR_VALUE_POS_X
	E_PBAR_VALUE_POS_Y
	E_PBAR_VALUE_RIGHT
	E_PBAR_VALUE_HEIGHT
	E_PBAR_BOUNDARY_SIZE // utilitário: tamanho do array
)

var directionSizeMult = []float32{
	1.0,  // RIGHT
	-1.0, // LEFT
	1.0,  // H_FROM_0
	-1.0, // UP
	1.0,  // DOWN
	-1.0, // V_FROM_0
}

var (
	InvalidPlayerError      = errors.New("attempt to create player progress bar for invalid player")
	InvalidProgressBarError = errors.New("invalid progress bar")
)

// ids dos textdraw slots (back, fill, main)
const (
	pbarBackSlot = 0
	pbarFillSlot = 1
	pbarMainSlot = 2
)

const invalidTextDrawID = -1

type progressBar struct {
	direction                 directionBar
	isCreated                 bool
	show                      bool
	posX, posY, posZ          float32
	width, height             float32
	color                     int
	minValue, value, maxValue float32
	paddingX, paddingY        float32

	// ids dos textdraws locais
	textdrawIDs [3]int
}

// CreateProgressBar cria e inicializa o progress bar associado ao ui.pID.
func (ui *UserInterface) CreateProgressBar(
	x, y, z float32,
	width, height float32,
	color int,
	maxValue float32,
	direction directionBar,
) error {
	var pOnline bool
	player.Builder().Select(ui.pID).Connected(&pOnline)

	if !pOnline {
		return InvalidPlayerError
	}

	// inicializar campos básicos
	ui.progressBar.direction = direction
	ui.progressBar.color = color
	ui.progressBar.height = height
	ui.progressBar.width = width
	ui.progressBar.maxValue = maxValue
	ui.progressBar.minValue = 0.0
	ui.progressBar.value = 0.0
	ui.progressBar.paddingX = 1.2
	ui.progressBar.paddingY = 1.0
	ui.progressBar.show = true
	ui.progressBar.isCreated = true
	ui.progressBar.posX = x
	ui.progressBar.posY = y
	ui.progressBar.posZ = z

	// marcar textdraws inválidos
	ui.progressBar.textdrawIDs[pbarBackSlot] = invalidTextDrawID
	ui.progressBar.textdrawIDs[pbarFillSlot] = invalidTextDrawID
	ui.progressBar.textdrawIDs[pbarMainSlot] = invalidTextDrawID

	// render inicial (cria textdraws)
	if err := ui.updateRender(); err != nil {
		// se falhar, garante estado consistente
		ui.DestroyProgressBar()
		return err
	}

	return nil
}

func (ui *UserInterface) DestroyProgressBar() {
	ui.destroyTextdraws()
	ui.progressBar.isCreated = false
	ui.progressBar.show = false
}

func (ui *UserInterface) SetPosProgressBar(x, y, z float32) error {
	ui.progressBar.posX, ui.progressBar.posY, ui.progressBar.posZ = x, y, z
	return ui.updateRender()
}

func (ui *UserInterface) SetProgressBarSize(width, height float32) error {
	ui.progressBar.width = width
	ui.progressBar.height = height
	return ui.updateRender()
}

func (ui *UserInterface) SetProgressBarColor(color int) error {
	ui.progressBar.color = color
	return ui.applyColorToTextdraws()
}

func (ui *UserInterface) SetProgressBarPadding(px, py float32) error {
	ui.progressBar.paddingX = px
	ui.progressBar.paddingY = py
	return ui.updateRender()
}

func (ui *UserInterface) SetProgressBarRange(min, max float32) error {
	ui.progressBar.minValue = min
	ui.progressBar.maxValue = max
	// garante valor dentro da faixa
	if ui.progressBar.value < min {
		ui.progressBar.value = min
	}
	if ui.progressBar.value > max {
		ui.progressBar.value = max
	}
	return ui.updateRender()
}

func (ui *UserInterface) GetProgressBarValue() float32 {
	return ui.progressBar.value
}

func (ui *UserInterface) SetProgressBarValue(v float32) error {
	if !ui.isValidProgressBar() {
		return InvalidProgressBarError
	}
	// clamp
	if v < ui.progressBar.minValue {
		v = ui.progressBar.minValue
	} else if v > ui.progressBar.maxValue {
		v = ui.progressBar.maxValue
	}
	ui.progressBar.value = v
	return ui.updateRender()
}

func (ui *UserInterface) ShowProgressBar() error {
	ui.progressBar.show = true
	return ui.updateRender()
}

func (ui *UserInterface) HideProgressBar() error {
	ui.progressBar.show = false
	// esconder textdraws se existirem
	ui.hideTextdraws()
	return nil
}

func (ui *UserInterface) SetProgressBarDirection(d directionBar) error {
	ui.progressBar.direction = d
	return ui.updateRender()
}

func (ui *UserInterface) isValidProgressBar() bool {
	if ui.pID <= -1 {
		return false
	}
	if !ui.progressBar.isCreated {
		return false
	}
	if ui.progressBar.maxValue < ui.progressBar.minValue {
		return false
	}
	return true
}

//
// helpers internos
//

func (ui *UserInterface) destroyTextdraws() {
	for i := 0; i < 3; i++ {
		id := ui.progressBar.textdrawIDs[i]
		if id != invalidTextDrawID {
			natives.PlayerTextDrawDestroy(ui.pID, id)
			ui.progressBar.textdrawIDs[i] = invalidTextDrawID
		}
	}
}

func (ui *UserInterface) hideTextdraws() {
	for i := 0; i < 3; i++ {
		id := ui.progressBar.textdrawIDs[i]
		if id != invalidTextDrawID {
			natives.PlayerTextDrawHide(ui.pID, id)
		}
	}
}

func (ui *UserInterface) showTextdraws() {
	for i := 0; i < 3; i++ {
		id := ui.progressBar.textdrawIDs[i]
		if id != invalidTextDrawID {
			natives.PlayerTextDrawShow(ui.pID, id)
		}
	}
}

const (
	maskLow   uint32 = 0x000000FF
	maskHigh  uint32 = 0xFFFFFF00
	halfAlpha uint32 = 0x66
)

// func (ui *UserInterface) applyColorToTextdraws() error {
// 	// Aplica cor aos textdraws já criados (box colors).
// 	// Assumimos que a cor tem o layout PAWN: 0xAABBCCDD ?
// 	// No PAWN original eles usavam compostos bitwise: caixa back = 0x00000000 | (colour & 0x000000FF)
// 	// e fill usa manipulação. Vamos replicar o comportamento esperado:

// 	color := int(ui.progressBar.color)

// 	backColor := color & maskLow

// 	fillColor := (color & maskHigh) |
// 		(halfAlpha & ((color & maskLow) / 2))

// 	// color := ui.progressBar.color
// 	// backColor := int(0x00000000) | (color & int(0x000000FF))

// 	// fillColor := (color & int(0xFFFFFF00)) |
// 	// 	(int(0x66) & ((color & int(0x000000FF)) / 2))
// 	mainColor := color

// 	if ui.progressBar.textdrawIDs[pbarBackSlot] != invalidTextDrawID {
// 		natives.PlayerTextDrawColor(ui.pID, ui.progressBar.textdrawIDs[pbarBackSlot], backColor)
// 	}
// 	if ui.progressBar.textdrawIDs[pbarFillSlot] != invalidTextDrawID {
// 		natives.PlayerTextDrawColor(ui.pID, ui.progressBar.textdrawIDs[pbarFillSlot], fillColor)
// 	}
// 	if ui.progressBar.textdrawIDs[pbarMainSlot] != invalidTextDrawID {
// 		natives.PlayerTextDrawColor(ui.pID, ui.progressBar.textdrawIDs[pbarMainSlot], mainColor)
// 	}
// 	return nil
// }

func (ui *UserInterface) applyColorToTextdraws() error {
	// Forçamos uint32 para evitar o overflow no 386
	color := uint32(ui.progressBar.color)

	// Fundo: pega apenas o alpha
	backColor := color & maskLow

	// Filler: limpa o alpha original e aplica a lógica de 50%
	fillAlpha := (color & maskLow) / 2
	fillColor := (color & maskHigh) | (halfAlpha & fillAlpha)

	mainColor := color

	// Na hora de passar para a nativa, fazemos o cast para int.
	// O Go vai apenas mover os bits, ignorando se o número parece "negativo".
	if id := ui.progressBar.textdrawIDs[pbarBackSlot]; id != invalidTextDrawID {
		natives.PlayerTextDrawBoxColor(ui.pID, id, int(backColor))
		natives.PlayerTextDrawColor(ui.pID, id, 0x00000000)
	}
	if id := ui.progressBar.textdrawIDs[pbarFillSlot]; id != invalidTextDrawID {
		natives.PlayerTextDrawBoxColor(ui.pID, id, int(fillColor))
		natives.PlayerTextDrawColor(ui.pID, id, 0x00000000)
	}
	if id := ui.progressBar.textdrawIDs[pbarMainSlot]; id != invalidTextDrawID {
		natives.PlayerTextDrawBoxColor(ui.pID, id, int(mainColor))
		natives.PlayerTextDrawColor(ui.pID, id, 0x00000000)
	}
	return nil
}

// isNeedToDrawValue — reproduz a lógica PAWN para exibir/ocultar o valor.
func isNeedToDrawValue(direction directionBar, curValue, minValue, maxValue float32) bool {
	if direction == BAR_DIRECTION_HORIZONTAL_FROM_0 || direction == BAR_DIRECTION_VERTICAL_FROM_0 {
		if maxValue < 0.0 {
			return curValue < maxValue
		} else if minValue > 0.0 {
			return curValue > minValue
		} else {
			return float32(math.Abs(float64(curValue))) > 0.001*(maxValue-minValue)
		}
	}
	return curValue > minValue
}

// barGetRatios — reproduz lógica de cálculo de ratio_from e ratio_to.
func barGetRatios(direction directionBar, curValue, minValue, maxValue float32) (ratioFrom, ratioTo float32) {
	rangeValue := maxValue - minValue
	if rangeValue == 0 {
		// evitar divisão por zero
		return 0, 0
	}
	if direction == BAR_DIRECTION_HORIZONTAL_FROM_0 || direction == BAR_DIRECTION_VERTICAL_FROM_0 {
		if maxValue < 0.0 {
			ratioFrom = 1.0
		} else if minValue > 0.0 {
			ratioFrom = 0.0
		} else {
			ratioFrom = -minValue / rangeValue
		}
	} else {
		ratioFrom = 0.0
	}
	ratioTo = (curValue - minValue) / rangeValue
	return
}

func normalizeRangeF(a, b *float32) {
	if *a > *b {
		tmp := *b
		*b = *a
		*a = tmp
	}
}

// computeBoundary — adapta PlayerBarUI_computeBoundry do PAWN para Go.
// Retorna array [E_PBAR_BOUNDARY_SIZE]float32 preenchida.
func (ui *UserInterface) computeBoundary() [E_PBAR_BOUNDARY_SIZE]float32 {
	var b [E_PBAR_BOUNDARY_SIZE]float32

	posX := ui.progressBar.posX
	posY := ui.progressBar.posY
	paddingX := ui.progressBar.paddingX
	paddingY := ui.progressBar.paddingY
	width := ui.progressBar.width
	height := ui.progressBar.height
	minValue := ui.progressBar.minValue
	maxValue := ui.progressBar.maxValue
	curValue := ui.progressBar.value
	direction := ui.progressBar.direction

	outerPosX2 := posX + width
	outerPosY2 := posY + height
	innerPosX1 := posX + paddingX
	innerPosX2 := outerPosX2 - paddingX
	innerPosY1 := posY + paddingY
	innerPosY2 := outerPosY2 - paddingY
	innerSizeX := innerPosX2 - innerPosX1
	innerSizeY := innerPosY2 - innerPosY1

	ratioFrom, ratioTo := barGetRatios(direction, curValue, minValue, maxValue)
	sizeMultiplier := directionSizeMult[direction]
	ratioFrom *= sizeMultiplier
	ratioTo *= sizeMultiplier

	isVertical := direction > BAR_DIRECTION_HORIZONTAL_FROM_0

	var valuePosX1, valuePosY1, valuePosX2, valuePosY2 float32
	if isVertical {
		valuePosX1 = innerPosX1
		valuePosX2 = innerPosX2
	} else {
		valuePosY1 = innerPosY1
		valuePosY2 = innerPosY2
	}

	// switch logic (replicando cases do PAWN)
	switch direction {
	case BAR_DIRECTION_RIGHT:
		valuePosX1 = innerPosX1
	case BAR_DIRECTION_LEFT:
		valuePosX1 = innerPosX2
	case BAR_DIRECTION_HORIZONTAL_FROM_0:
		valuePosX1 = innerPosX1
	case BAR_DIRECTION_UP:
		valuePosY1 = innerPosY2
	case BAR_DIRECTION_DOWN:
		valuePosY1 = innerPosY1
	case BAR_DIRECTION_VERTICAL_FROM_0:
		valuePosY1 = innerPosY2
	}

	if isVertical {
		valuePosY2 = valuePosY1
		valuePosY1 += innerSizeY * ratioFrom
		valuePosY2 += innerSizeY * ratioTo
	} else {
		valuePosX2 = valuePosX1
		valuePosX1 += innerSizeX * ratioFrom
		valuePosX2 += innerSizeX * ratioTo
	}

	normalizeRangeF(&valuePosX1, &valuePosX2)
	normalizeRangeF(&valuePosY1, &valuePosY2)

	correctionX := float32(1.25)
	valuePosX1 += correctionX
	valuePosX2 -= correctionX
	innerPosX1 += correctionX
	innerPosX2 -= correctionX

	b[E_PBAR_BACKGROUND_POS_X] = posX
	b[E_PBAR_BACKGROUND_POS_Y] = posY
	b[E_PBAR_BACKGROUND_RIGHT] = outerPosX2
	b[E_PBAR_BACKGROUND_HEIGHT] = 0.1 * (outerPosY2 - posY)
	b[E_PBAR_FILLER_POS_X] = innerPosX1
	b[E_PBAR_FILLER_POS_Y] = innerPosY1
	b[E_PBAR_FILLER_RIGHT] = innerPosX2
	b[E_PBAR_FILLER_HEIGHT] = 0.1 * (innerPosY2 - innerPosY1)
	b[E_PBAR_VALUE_POS_X] = valuePosX1
	b[E_PBAR_VALUE_POS_Y] = valuePosY1
	b[E_PBAR_VALUE_RIGHT] = valuePosX2
	// b[E_PBAR_VALUE_HEIGHT] = 0.1 * (valuePosY2 - valuePosY1)
	b[E_PBAR_VALUE_HEIGHT] = 0.1 * (innerPosY2 - innerPosY1)


	return b
}

// createGeometry — cria (ou recria) os textdraws conforme boundary.
func (ui *UserInterface) createGeometry(boundary [E_PBAR_BOUNDARY_SIZE]float32, drawMain bool) {
	// destrói textdraws antigos (se existirem)
	ui.destroyTextdraws()

	// background
	ptdBack := natives.CreatePlayerTextDraw(ui.pID, boundary[E_PBAR_BACKGROUND_POS_X], boundary[E_PBAR_BACKGROUND_POS_Y], "_")
	natives.PlayerTextDrawTextSize(ui.pID, ptdBack, boundary[E_PBAR_BACKGROUND_RIGHT], 0.0)
	natives.PlayerTextDrawLetterSize(ui.pID, ptdBack, 1.0, boundary[E_PBAR_BACKGROUND_HEIGHT])
	natives.PlayerTextDrawUseBox(ui.pID, ptdBack, true)

	// filler
	ptdFill := natives.CreatePlayerTextDraw(ui.pID, boundary[E_PBAR_FILLER_POS_X], boundary[E_PBAR_FILLER_POS_Y], "_")
	natives.PlayerTextDrawTextSize(ui.pID, ptdFill, boundary[E_PBAR_FILLER_RIGHT], 0.0)
	natives.PlayerTextDrawLetterSize(ui.pID, ptdFill, 1.0, boundary[E_PBAR_FILLER_HEIGHT])
	natives.PlayerTextDrawUseBox(ui.pID, ptdFill, true)

	// main/value
	ptdMain := natives.CreatePlayerTextDraw(ui.pID, boundary[E_PBAR_VALUE_POS_X], boundary[E_PBAR_VALUE_POS_Y], "_")
	natives.PlayerTextDrawTextSize(ui.pID, ptdMain, boundary[E_PBAR_VALUE_RIGHT], 0.0)
	natives.PlayerTextDrawLetterSize(ui.pID, ptdMain, 1.0, boundary[E_PBAR_VALUE_HEIGHT])
	natives.PlayerTextDrawUseBox(ui.pID, ptdMain, drawMain)

	ui.progressBar.textdrawIDs[pbarBackSlot] = ptdBack
	ui.progressBar.textdrawIDs[pbarFillSlot] = ptdFill
	ui.progressBar.textdrawIDs[pbarMainSlot] = ptdMain

	// aplica cor conforme lógica PAWN
	ui.applyColorToTextdraws()
}

// updateRender — recalcula boundary, cria textdraws e mostra/esconde conforme estado.
func (ui *UserInterface) updateRender() error {
	var pOnline bool
	player.Builder().Select(ui.pID).Connected(&pOnline)
	if !pOnline {
		return InvalidPlayerError
	}
	if !ui.isValidProgressBar() {
		return InvalidProgressBarError
	}

	// calcula boundary
	b := ui.computeBoundary()

	// decide se desenhar main/value
	drawMain := isNeedToDrawValue(ui.progressBar.direction, ui.progressBar.value, ui.progressBar.minValue, ui.progressBar.maxValue)

	// cria/recria geometry
	ui.createGeometry(b, drawMain)

	// mostra se estiver visível
	if ui.progressBar.show {
		ui.showTextdraws()
	} else {
		ui.hideTextdraws()
	}

	return nil
}
