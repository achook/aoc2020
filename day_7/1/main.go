package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

func findGold(lookIn string, bags map[string][]string) bool {
	canFind, ok := bags[lookIn]
	if !ok {
		return false
	}

	for _, color := range canFind {
		if color == "shiny gold" {
			return true
		}

		if findGold(color, bags) {
			return true
		}
	}

	return false
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
			canFit[i] = strings.Trim(canFit[i], "123456789. ")
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

	num := 0

	for color := range bags {
		if findGold(color, bags) {
			num++
		}
	}

	fmt.Println(num)
}
