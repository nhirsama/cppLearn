// A. Quintomania.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}
func nhir() {
	var n int64
	fmt.Fscan(r, &n)
	v := make([]int64, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(r, &v[i])
	}
	for i := int64(1); i < n; i++ {
		if abs(v[i]-v[i-1]) != 5 && abs(v[i]-v[i-1]) != 7 {
			fmt.Fprintln(w, "NO")
			return
		}
	}
	fmt.Fprintln(w, "YES")

}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
