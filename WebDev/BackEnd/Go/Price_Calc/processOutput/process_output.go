package processOutput

import (
	"encoding/json"
	"errors"
	"os"
)

func WriteJSON(outFilePath string, data any) error {
	outFile, err := os.Create(outFilePath)

	if err != nil {
		return errors.New("Failed to Create " + outFilePath)
	}

	encoder := json.NewEncoder(outFile)
	err = encoder.Encode(data)

	if err != nil {
		outFile.Close()
		return errors.New("Failed to covert data to JSON")
	}

	outFile.Close()
	return nil
}
