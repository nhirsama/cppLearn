// C. A Good Problem.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var n, l, rr, k int64
	fmt.Fscan(r, &n, &l, &rr, &k)
	if n%2 == 1 {
		fmt.Fprintln(w, l)
	} else {
		if n == 2 {
			fmt.Fprintln(w, -1)
		} else {
			var t int64 = 1
			for ; (t <= rr && (t&l) != 0) || t < l; t <<= 1 {
			}
			if t <= rr && (t&l) == 0 {
				if k <= n-2 {
					fmt.Fprintln(w, l)
				} else {
					fmt.Fprintln(w, t)
				}
			} else {
				fmt.Fprintln(w, -1)
			}
		}
	}
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		go nhir()
	}
	defer w.Flush()
}
