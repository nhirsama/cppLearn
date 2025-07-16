// B. Kevin and Permutation.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var a, b int
	fmt.Fscan(r, &a, &b)
	var l, rr int = 1, a
	for i := 0; i < a; i++ {
		if i%b == b-1 {
			fmt.Fprintf(w, "%d ", l)
			l++
		} else {
			fmt.Fprintf(w, "%d ", rr)
			rr--
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
