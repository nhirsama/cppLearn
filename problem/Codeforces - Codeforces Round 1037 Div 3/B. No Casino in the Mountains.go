// B. No Casino in the Mountains.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var n, k int
	fmt.Fscan(r, &n, &k)
	v := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &v[i])
	}
	var ans, cnt int
	var t bool
	for _, i := range v {
		if t {
			cnt = 0
			t = false
		} else {
			if i == 0 {
				cnt++
			} else {
				cnt = 0
			}
			if cnt >= k {
				cnt = 0
				t = true
				ans++
			}
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
