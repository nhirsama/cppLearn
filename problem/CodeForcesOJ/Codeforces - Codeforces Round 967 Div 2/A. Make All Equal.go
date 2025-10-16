package main

import (
	"fmt"
	"slices"
)

func nhir() {
	var n int64
	fmt.Scan(&n)
	arr := make([]int64, n)
	for i := int64(0); i < n; i++ {
		var tmp int64
		fmt.Scan(&tmp)
		arr[tmp-1]++
	}
	max := slices.Max(arr)
	fmt.Println(n - max)
}
func main() {
	var T = 1
	fmt.Scan(&T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
}
