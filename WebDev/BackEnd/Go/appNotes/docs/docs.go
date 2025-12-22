package docs

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"strings"

	"example.com/note/user"
)

const basePath = "/home/arnab/CodeAyan/CodeRepo/WebDev/BackEnd/Go/appNotes/"

type Document struct {
	Creator user.User `json:"creator"`
	Path    string    `json:"path"`
	Content string    `json:"content"`
}

func (this *Document) New(appUser user.User, docName string) {
	this.Creator = appUser
	this.Path = basePath + docName + ".json"

	fmt.Println("New Document Created at:", this.Path)
}

func (this *Document) Write() {
	fmt.Print("Enter Your file Content: ")

	reader := bufio.NewReader(os.Stdin)
	text, err := reader.ReadString('\n')

	if err != nil {
		fmt.Println("Error:", err)
		text = ""
	}

	text = strings.TrimSuffix(text, "\n")
	text = strings.TrimSuffix(text, "\r")
	this.Content = text

	jsonDoc, err := json.Marshal(this)

	if err != nil {
		fmt.Println("Error:", err)
		fmt.Println("Write Failed!")
		return
	}

	os.WriteFile(this.Path, jsonDoc, 0644)
}

func (this *Document) GetCreator() user.User {
	return this.Creator
}
