package main

import (
	"fmt"
)

func nhir() {
	var l, r int
	_, err := fmt.Scan(&l, &r)
	if err != nil {
		return
	}
	fmt.Println(((r+1)/2 - l/2) / 2)
}
func main() {
	var T = 1
	_, err := fmt.Scan(&T)
	if err != nil {
		return
	}
	for _i := 0; _i < T; _i++ {
		nhir()
	}
}
