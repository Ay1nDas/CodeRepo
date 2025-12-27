package conversion

import (
	"errors"
	"strconv"
)

func ParseToFloat(floatStr []string) ([]float64, error) {
	retFloat := make([]float64, len(floatStr))
	for i, str := range floatStr {
		floatValue, err := strconv.ParseFloat(str, 64)

		if err != nil {
			return []float64{}, errors.New("Failed to Parse " + str)
		}
		retFloat[i] = floatValue
	}

	return retFloat, nil
}
