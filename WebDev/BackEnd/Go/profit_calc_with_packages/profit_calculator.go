package main

import (
	"errors"
	"fmt"
	"myFile/errout"
	"os"
)

const resultFile = "/home/arnab/CodeAyan/CodeRepo/WebDev/BackEnd/Go/profit_calc_with_packages/result.txt"

func main() {
	var revenue, expenses, taxRate float64

	fmt.Print("Enter Revenue: ")
	_, err := fmt.Scan(&revenue)
	if err != nil {
		errout.OutputErr(err)
		return
	}

	fmt.Print("Enter Expenses: ")
	_, err = fmt.Scan(&expenses)
	if err != nil {
		errout.OutputErr(err)
		return
	}

	fmt.Print("Enter Tax Rate: ")
	_, err = fmt.Scan(&taxRate)
	if err != nil {
		errout.OutputErr(err)
		return
	}

	if revenue <= 0 {
		err = errors.New("revenue can not be negative or zero")
	} else if expenses <= 0 {
		err = errors.New("expenses can not be negative or zero")
	} else if taxRate <= 0 {
		err = errors.New("tax rate can not be negative or zero")
	}

	if err != nil {
		errout.OutputErr(err)
		return
	}

	earningBeforeTax := revenue - expenses
	earningAfterTax := earningBeforeTax - earningBeforeTax*taxRate/100
	ratio := earningBeforeTax / earningAfterTax

	fmt.Println("EBT:", earningBeforeTax)
	fmt.Println("Profit:", earningAfterTax)

	fmt.Println("Ratio:", ratio)

	data := []byte(fmt.Sprintf("EBT: %.2f\nEAT: %.2f\nRatio: %.2f", earningBeforeTax, earningAfterTax, ratio))
	os.WriteFile(resultFile, data, 0644)
}
