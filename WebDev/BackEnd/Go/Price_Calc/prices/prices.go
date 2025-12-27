package prices

import (
	"bufio"
	"fmt"
	"os"

	"example.com/price-calculator/conversion"
	"example.com/price-calculator/processOutput"
)

type TaxIncludedPriceJob struct {
	TaxRate           float64
	InputPrices       []float64
	TaxIncludedPrices map[string]string
}

func (job *TaxIncludedPriceJob) LoadData(inFilePath string) {
	inputFile, err := os.Open(inFilePath)

	if err != nil {
		fmt.Println("Could not open file", inFilePath)
		fmt.Println("Error:", err)

		inputFile.Close()
		return
	}

	scanner := bufio.NewScanner(inputFile)
	priceStr := []string{}

	for scanner.Scan() {
		priceStr = append(priceStr, scanner.Text())
	}

	job.InputPrices, err = conversion.ParseToFloat(priceStr)
	if err != nil {
		fmt.Println(err)
	}

	inputFile.Close()
}

func (job TaxIncludedPriceJob) Process(path string) {
	job.LoadData(path + "inputPrice.txt")

	job.TaxIncludedPrices = make(map[string]string)
	for _, price := range job.InputPrices {
		priceWithTax := price * (1 + job.TaxRate)
		job.TaxIncludedPrices[fmt.Sprintf("%.2f", price)] = fmt.Sprintf("%.2f", priceWithTax)
	}

	outFilePath := path + fmt.Sprintf("outputPrice_%.0f.json", job.TaxRate*100)
	processOutput.WriteJSON(outFilePath, job)
}

func NewTaxIncludedPriceJob(taxRate float64) *TaxIncludedPriceJob {
	return &TaxIncludedPriceJob{
		InputPrices: []float64{},
		TaxRate:     taxRate,
	}
}
