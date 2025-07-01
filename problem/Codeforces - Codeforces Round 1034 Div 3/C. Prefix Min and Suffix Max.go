// C. Prefix Min and Suffix Max.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var n int64
	fmt.Fscan(r, &n)
	v := make([]int64, n)
	minpre := make([]int64, n+2)
	maxsuf := make([]int64, n+2)
	for i := int64(0); i < n+2; i++ {
		minpre[i] = 0x3f3f3f3f3f3f3f3f
	}
	for i := int64(0); i < n; i++ {
		fmt.Fscan(r, &v[i])
		minpre[i+1] = min(minpre[i], v[i])
	}
	for i := n - 1; i >= 0; i-- {
		maxsuf[i+1] = max(maxsuf[i+2], v[i])
	}
	for i := int64(0); i < n; i++ {
		if maxsuf[i+1] == v[i] || minpre[i+1] == v[i] {
			fmt.Fprint(w, 1)
		} else {
			fmt.Fprint(w, 0)
		}
	}
	fmt.Fprintln(w)
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
