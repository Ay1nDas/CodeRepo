package main

import "fmt"

type Product struct {
	title string
	id    int
	price float64
}

func main() {
	hobbies := [3]string{"badminton", "tennis", "gaming"}
	fmt.Println(hobbies)

	fmt.Println(hobbies[0])
	hobbies2 := hobbies[1:3]
	fmt.Println(hobbies2)

	// hobbies3 := hobbies[:2]
	hobbies3 := hobbies[0:2]

	fmt.Println(hobbies3)
	hobbies3 = hobbies3[1:3]
	fmt.Println(hobbies3)

	goals := []string{"Back-end", "Contribution"}
	fmt.Println(goals)

	goals[1] = "LFX"
	goals = append(goals, "Projects")
	fmt.Println(goals)

	products := []Product{
		{
			"Soap",
			101,
			6.99,
		},
		{
			"Chips",
			102,
			1.99,
		},
	}
	fmt.Println(products)

	products = append(products, Product{
		"Detergent",
		103,
		10.99,
	})
	fmt.Println(products)
}
