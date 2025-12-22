package main

import (
	"fmt"
	"time"
)

type user struct {
	firstName string
	lastName  string
	birthDate string
	createdAt time.Time
}

func main() {
	userFirstName := getData("Enter Your First name: ")
	userLastName := getData("Enter Your Last name: ")
	userBirthDate := getData("Enter Your Birth Date(DD-MM-YYYY): ")

	var appUser user
	// appUser := user{}
	// appUser.firstName = userFirstName
	// appUser.lastName = userLastName
	// appUser.birthDate = userBirthDate
	// appUser.createdAt = time.Now()
	appUser = user{
		userFirstName,
		userLastName,
		userBirthDate,
		time.Now(),
	}

	appUser.OutputDetails()
}

func getData(str string) string {
	fmt.Print(str)
	var ret string
	fmt.Scan(&ret)

	return ret
}

func (this user) OutputDetails() {
	fmt.Println(this.firstName, this.lastName, this.birthDate)
}
