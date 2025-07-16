// A. Add or XOR.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var a, b, x, y int
	fmt.Fscan(r, &a, &b, &x, &y)
	if b < a-(a&1) {
		fmt.Fprintln(w, -1)
	} else if b >= a {
		var cnt int
		for ; a < b; a++ {
			if (a & 1) == 0 {
				cnt += min(x, y)
			} else {
				cnt += x
			}

		}
		fmt.Fprintln(w, cnt)
	} else {
		fmt.Fprintln(w, y)
	}
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
