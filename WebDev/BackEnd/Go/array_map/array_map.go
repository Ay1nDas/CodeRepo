package main

import "fmt"

func main() {
	// arr := []int{}
	// fmt.Println(arr)

	// freq := map[int]int{}

	// freq[1] = 2
	// freq[4] = 8
	// fmt.Println(freq)

	// for i, val := range freq {
	// 	fmt.Println(i, val)
	// }

	arr := [4]int{1, 2, 3, 4}
	fmt.Println(arr)

	arrSlice := arr[1:3]
	fmt.Println(arrSlice)

	arrSlice2 := arrSlice[:1]
	arrSlice2 = arrSlice2[:3]
	fmt.Println(arrSlice2)
}
