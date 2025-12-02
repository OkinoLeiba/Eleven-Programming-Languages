package main

import "fmt"

func combination(combinArray [4]int) int {
	combinResult := 1
	for i := 0; i < len(combinArray); i++ {
		combinResult *= combinArray[i]
	}
	fmt.Println(combinResult)
	return combinResult
}

type robotResult = [2]int

func robotTrack(n int, w int, s int, e int) robotResult {
	var l int = 0
	var r int = 0

	l = n + (s * -1)
	r = w + (e * -1)

	var robotResult = [2]int{l, r}

	fmt.Println("Robot Track", robotResult)
	return robotResult

}

func main() {

	fmt.Println("Hello World!")
	combinArray := [4]int{2, 3, 4, 5}
	combination(combinArray)
	robotTrack(-20, 10, 20, 0)
}
