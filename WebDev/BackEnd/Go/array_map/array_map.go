package main

import "fmt"

func main() {
	arr := []int{}
	fmt.Println(arr)

	freq := map[int]int{}

	freq[1] = 2
	freq[4] = 8
	fmt.Println(freq)

	for i, val := range freq {
		fmt.Println(i, val)
	}
}
