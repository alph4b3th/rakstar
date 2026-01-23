package ui

import "github.com/alph4b3th/rakstar/utils"

func (ui *UserInterface) Select(arg interface{}) {
	ui.pID = utils.SelectPlayer(arg)
}
