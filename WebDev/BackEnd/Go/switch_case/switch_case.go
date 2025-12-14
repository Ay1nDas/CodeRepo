package main

import "fmt"

func main() {
	i := 2

	if num := 12; num > 0 {
		fmt.Println(num)
	}

	switch i {
	case 0:
		fmt.Println(i)
	case 1:
		fmt.Println(i)
	case 2, 3, 4:
		fallthrough
	default:
		fmt.Println(i)
	}
}
