package main

import "fmt"

func main() {
	// fmt.Println("WOW")
	// i := 2
	// for ; ; i++ {
	// 	fmt.Println("WOW", i)
	// }

	nums := []int{10, 20, 30, 40}

	for val := range nums {
		fmt.Println(val)
	}
}
