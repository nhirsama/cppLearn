// E. MEX Count.go
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
	cnt := make([]int64, n+1)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(r, &v[i])
		cnt[v[i]]++
	}
	for i := int64(0); i < n; i++ {
		if cnt[i] == 0 {
			cnt[i+1] = 0
		}
	}
	//fmt.Fprint(w, cnt)

	cf := make([]int64, n+2)
	f := true
	for i := int64(0); i < n+1; i++ {
		if f {
			if cnt[i] <= n-i {
				cf[cnt[i]]++
				cf[n-i+1]--
			}
			if cnt[i] == 0 {
				f = false
			}
		}
	}
	//fmt.Fprint(w, cf)
	for i := int64(0); i < n+1; i++ {
		cf[i+1] += cf[i]
	}
	for i := int64(0); i < n+1; i++ {
		fmt.Fprintf(w, "%d ", cf[i])
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
