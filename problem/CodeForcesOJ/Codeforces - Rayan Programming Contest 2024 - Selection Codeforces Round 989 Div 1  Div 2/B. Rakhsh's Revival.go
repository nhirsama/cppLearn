// B. Rakhsh's Revival.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var n, m, k int
	fmt.Fscan(r, &n, &m, &k)
	var s string
	fmt.Fscan(r, &s)
	var ans, cnt int
	s = s + "1"
	for i := 0; i < n; i++ {
		if s[i] == '0' {
			cnt++
			if cnt >= m {
				ans++
				i += k - 1
				cnt = 0
			}
		} else {
			cnt = 0
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
