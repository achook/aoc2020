package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func main() {
	var numbers []int

	file, err := os.Open("input.txt")
	if err != nil {
		log.Fatal(err)
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		number, err := strconv.Atoi(scanner.Text())
		if err != nil {
			log.Fatal(err)
			return
		}
		numbers = append(numbers, number)
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
		return
	}

	for i, firstNumber := range numbers {
		lookFor := 2020 - firstNumber

		for j, secondNumber := range numbers {
			if i == j {
				continue
			}

			if secondNumber == lookFor {
				fmt.Println(firstNumber * secondNumber)
				return
			}

		}
	}
}
