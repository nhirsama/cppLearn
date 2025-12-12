// B_Optimal_Shifts.go
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
	var s string
	fmt.Fscan(r, &s)
	s = s + s
	var t, ans int
	for _, c := range s {
		if c == '0' {
			t++
		} else {
			ans = max(t, ans)
			t = 0
		}
	}
	fmt.Fprintln(w, ans)
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
