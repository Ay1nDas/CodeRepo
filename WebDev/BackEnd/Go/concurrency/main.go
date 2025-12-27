package main

import (
	"fmt"
	"time"
)

func greet() {
	fmt.Println("Hello! Ayan.")
}

func slowGreet1(isDone chan bool) {
	time.Sleep(3 * time.Second)
	fmt.Println("1. Slow Hello! Ayan.")

	isDone <- true
}

func slowGreet2(isDone chan bool) {
	time.Sleep(time.Second)
	fmt.Println("2. Slow Hello! Ayan.")

	isDone <- true
	time.Sleep(time.Second)
	fmt.Println("2. Slow Hello! Ayan.")
}

func main() {
	greet()

	doneChan := make(chan bool)
	go slowGreet2(doneChan)
	<-doneChan
	greet()
	time.Sleep(2 * time.Second)
}
