package main

import (
	"fmt"
	"os"
)

const filePath = "/home/arnab/CodeAyan/CodeRepo/WebDev/BackEnd/Go/file_io/file.txt"

func main() {
	err := os.WriteFile(filePath, []byte("Hello"), 0644)
	if err != nil {
		fmt.Println("ERROR writing!")
		fmt.Println(err)
		return
	}

	data, err := os.ReadFile(filePath)

	fmt.Println(string(data))
}
