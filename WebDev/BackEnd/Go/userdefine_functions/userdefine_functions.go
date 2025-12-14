package main

import "fmt"

func print(a int) (f float64, err error) {
	fmt.Println("Hello")
	err = nil
	f = float64(a) + 0.1
	return
}

func main() {
	fmt.Println(print(12))
}
