// C. I Will Definitely Make It.go
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
	var tt = v[k-1]
	sort.Slice(v, func(i, j int) bool { return v[i] < v[j] })
	var t int
	for i := 0; i < n-1; i++ {
		if v[i] < tt {
			continue
		}
		t = max(t, v[i+1]-v[i])
	}
	if t <= tt {
		fmt.Fprintln(w, "YES")
	} else {
		fmt.Fprintln(w, "NO")
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
