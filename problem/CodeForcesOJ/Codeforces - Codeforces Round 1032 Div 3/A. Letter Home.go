package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func Abs_min(x, y int64) int64 {
	if x < 0 {
		x = -x
	}
	if y < 0 {
		y = -y
	}
	if x > y {
		return y
	}
	return x
}
func nhir() {
	var n, s int64
	fmt.Fscan(r, &n, &s)
	var arr = make([]int64, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(r, &arr[i])
	}
	max := slices.Max(arr)
	min := slices.Min(arr)

	fmt.Fprintln(w, max-min+Abs_min(s-min, s-max))
}
func main() {
	defer w.Flush()
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
}
