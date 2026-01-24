package progressbar2

import "github.com/alph4b3th/rakstar/utils"

func (ui *UserInterface) Select(arg interface{}) *UserInterface {
	ui.pID = utils.SelectPlayer(arg)
	return ui
}
