package main

import "fmt"

func main() {
	var n int64
	fmt.Scan(&n)
	var sum float64
	var i float64
	for i = 1; sum <= float64(n); i++ {
		sum += 1 / i
	}
	fmt.Println(i - 1)
}
