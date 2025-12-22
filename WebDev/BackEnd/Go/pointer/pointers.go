package main

import "fmt"

func main() {
	age := 21

	var agePtr *int
	agePtr = &age

	fmt.Println(agePtr)
	fmt.Println(*agePtr)

	var str string = "AYAN"

	fmt.Print(str)
	change(str)
	fmt.Print(str)
}

func change(str string) {

}
