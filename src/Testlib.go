package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	var str string
	fmt.Scan(&str)
	for i := 0; i < n; i++ {
		fmt.Println(str)
	}
}
