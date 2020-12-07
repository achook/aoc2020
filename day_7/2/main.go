package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func findChildren(color string, mappings map[string][]string) int {
	count := 0

	if _, ok := mappings[color]; !ok {
		return count
	}

	for _, bag := range mappings[color] {
		splitted := strings.SplitN(bag, " ", 2)
		amount, _ := strconv.Atoi(splitted[0])
		color := splitted[1]
		count += amount
		count += amount * findChildren(color, mappings)
	}

	return count
}

func main() {
	file, err := os.Open("input.txt")
	if err != nil {
		log.Fatal(err)
		return
	}
	defer file.Close()

	bags := make(map[string][]string)

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()

		tokens := strings.Split(line, " contain ")
		if len(tokens) != 2 {
			log.Fatal("ERROR")
		}

		color := tokens[0]
		color = strings.TrimSuffix(color, " bags")
		canFit := strings.Split(tokens[1], ",")

		for i := range canFit {
			canFit[i] = strings.Trim(canFit[i], ". ")
			canFit[i] = strings.TrimSuffix(canFit[i], " bags")
			canFit[i] = strings.TrimSuffix(canFit[i], " bag")
		}

		if len(canFit) == 1 && canFit[0] == "no other" {
			continue
		}

		bags[color] = canFit
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
		return
	}

	fmt.Println(findChildren("shiny gold", bags))

}
