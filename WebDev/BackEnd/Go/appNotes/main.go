package main

import (
	"example.com/note/docs"
	"example.com/note/user"
)

func main() {
	var appUser user.User
	appUser.New()
	appUser.Display()

	var newDoc docs.Document
	newDoc.New(appUser, "myDoc")

	newDoc.Write()
}
