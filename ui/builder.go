package ui

type UserInterface struct {
	pID         int
	progressBar progressBar
}

func Builder() *UserInterface {
	return new(UserInterface)
}
