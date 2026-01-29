package utils

import (
	"errors"
	"time"

	"github.com/golang-jwt/jwt/v5"
)

const secretKey = "exampleKey"

func GenerateToken(email string, userId int64) (string, error) {
	token := jwt.NewWithClaims(jwt.SigningMethodHS256, jwt.MapClaims{
		"email":  email,
		"userId": userId,
		"exp":    time.Now().Add(time.Hour * 2).Unix(),
	})

	return token.SignedString([]byte(secretKey))
}

func VerifyToken(token string) (error, int64) {
	parsedToken, err := jwt.Parse(token, func(jwtToken *jwt.Token) (interface{}, error) { // USE any?
		_, ok := jwtToken.Method.(*jwt.SigningMethodHMAC) // Use HS256 insteed of HMCA?

		if !ok {
			return nil, errors.New("Unexpected Signing Method!")
		}

		return []byte(secretKey), nil
	})

	if err != nil {
		return err, 0
	}

	if !parsedToken.Valid {
		return errors.New("Invalid Token!"), 0
	}

	claims, ok := parsedToken.Claims.(jwt.MapClaims)
	if !ok {
		return errors.New("Invalid Token Claims"), 0
	}

	userId := int64(claims["userId"].(float64))

	return nil, userId
}
