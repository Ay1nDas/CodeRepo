package main

import "fmt"

func main() {
	// double := createFunc(3)

	fmt.Println(createFunc(3)(7))
}

func createFunc(fact int) func(int) int {
	return func(num int) int {
		return num * fact
	}
}
