// B. Grab the Candies.go
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
	var t, odd, even int
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &t)
		if t%2 == 0 {
			even += t
		} else {
			odd += t
		}
	}
	if odd >= even {
		fmt.Fprintln(w, "NO")
	} else {
		fmt.Fprintln(w, "YES")
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
