package dialog

func (db *DialogBuilder) GetButton(response *string) *DialogBuilder {
	switch db.DialogResponse.Response {
	case 1:
		*response = "left"
	case 0:
		*response = "right"
	default:
		*response = ""
	}
	return db
}

func (db *DialogBuilder) GetListItem(listItem *int) *DialogBuilder {
	*listItem = db.DialogResponse.Listitem
	return db
}

func (db *DialogBuilder) GetText(text *string) *DialogBuilder {
	*text = db.DialogResponse.Inputtext
	return db
}

func (db *DialogBuilder) GetErr(err *error) *DialogBuilder {
	*err = db.Err
	return db
}
