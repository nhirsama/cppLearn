// B. Pile Shuffling.go
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
	var ans int64
	fmt.Fscan(r, &n)
	for i := 0; i < n; i++ {
		var a, b, c, d int64
		fmt.Fscan(r, &a, &b, &c, &d)
		if b <= d {
			ans += max(a-c, 0)
		} else {
			ans += b - d + a
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
