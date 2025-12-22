package user

import (
	"errors"
	"fmt"
)

type User struct {
	FirstName string
	LastName  string
	UId       string
}

func (this *User) New() error {
	fmt.Print("Enter Your name: [First Name] [Last Name]: ")
	fmt.Scan(&this.FirstName) // Check 1 line works
	fmt.Scan(&this.LastName)

	if this.FirstName == "" || this.LastName == "" {
		return errors.New("Invalid Name! First and last name should contain atleast 1 charecter.")
	} else {
		this.UId = this.FirstName + "_" + this.LastName
		return nil
	}
}

func (this *User) Display() {
	fmt.Println("User:", this.FirstName, this.LastName)
	fmt.Println("uId:", this.UId)
}
