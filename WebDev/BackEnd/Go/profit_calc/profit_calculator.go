package main

import (
	"errors"
	"fmt"
	"os"
)

const resultFile = "/home/arnab/CodeAyan/CodeRepo/WebDev/BackEnd/Go/profit_calc/result.txt"

func main() {
	var revenue, expenses, taxRate float64

	fmt.Print("Enter Revenue: ")
	_, err := fmt.Scan(&revenue)
	if err != nil {
		outputErr(err)
		return
	}

	fmt.Print("Enter Expenses: ")
	_, err = fmt.Scan(&expenses)
	if err != nil {
		outputErr(err)
		return
	}

	fmt.Print("Enter Tax Rate: ")
	_, err = fmt.Scan(&taxRate)
	if err != nil {
		outputErr(err)
		return
	}

	if revenue <= 0 {
		err = errors.New("Revenue Can not be negative or Zero")
	} else if expenses <= 0 {
		err = errors.New("Expenses Can not be negative or Zero")
	} else if taxRate <= 0 {
		err = errors.New("Tax Rate Can not be negative or Zero")
	}

	if err != nil {
		outputErr(err)
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

func outputErr(err error) {
	fmt.Print("Error: ")
	fmt.Println(err)
}
