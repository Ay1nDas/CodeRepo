package main

import "example.com/price-calculator/prices"

const path = "/home/arnab/CodeAyan/CodeRepo/WebDev/BackEnd/Go/Price_Calc/"

func main() {
	taxRates := []float64{0.00, 0.07, 0.10, 0.15}

	for _, taxRate := range taxRates {
		priceJob := prices.NewTaxIncludedPriceJob(taxRate)
		priceJob.Process(path)
	}
}
