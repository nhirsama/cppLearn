// A_Operations_with_Inversions.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var n int
	fmt.Fscan(r, &n)
	var v []int = make([]int, n)
	var ans, t int
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &v[i])
		if v[i] >= t {
			ans++
			t = v[i]
		}
	}
	fmt.Fprintln(w, n-ans)
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
