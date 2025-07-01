// B. Tournament.go
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
	var n, j, k int64
	fmt.Fscan(r, &n, &j, &k)
	v := make([]int64, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(r, &v[i])
	}
	t := v[j-1]
	sort.Slice(v, func(i, j int) bool {
		return v[i] < v[j]
	})
	if k == 1 && v[n-1] > t {
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
