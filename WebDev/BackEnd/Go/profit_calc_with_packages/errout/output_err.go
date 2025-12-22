package errout

import (
	"fmt"
)

func OutputErr(err error) {
	fmt.Print("Error: ")
	fmt.Println(err)
}
