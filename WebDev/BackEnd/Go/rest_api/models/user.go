package models

import (
	"errors"
	"fmt"

	db "example.com/restapi/data-base"
	"example.com/restapi/utils"
)

type User struct {
	ID       int64
	Email    string `binding:"required"`
	Password string `binding:"required"`
}

func (u *User) Save() error {
	insertUserQuery := `
	INSERT INTO users(email, password) 
	VALUES (?, ?)`
	statement, err := db.DB.Prepare(insertUserQuery)
	if err != nil {
		return err
	}
	defer statement.Close() // Called while returning

	hashedPassword, err := utils.HashPassword(u.Password)
	if err != nil {
		return err
	}

	result, err := statement.Exec(u.Email, hashedPassword)
	if err != nil {
		return err
	}
	u.ID, err = result.LastInsertId()

	return err
}

func (u *User) ValidateUser() error {
	findQuery := `SELECT id, password FROM users WHERE email = ?`
	statement, err := db.DB.Prepare(findQuery)
	if err != nil {
		return err
	}
	defer statement.Close()

	row := statement.QueryRow(u.Email)

	var retrievedPass string
	err = row.Scan(&u.ID, &retrievedPass)

	if err != nil {
		return errors.New(fmt.Sprint("The Provided email doesn't match any registered user!\n", err))
	}

	isValidPass := utils.CheckPasswordHash(retrievedPass, u.Password)
	if !isValidPass {
		return errors.New("Wrong Password!")
	}

	return nil
}
