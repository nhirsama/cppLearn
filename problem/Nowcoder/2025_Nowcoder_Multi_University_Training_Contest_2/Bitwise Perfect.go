// Bitwise Perfect.go
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
	var n int64
	fmt.Fscan(r, &n)
	v := make([]int64, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(r, &v[i])
		fmt.Printf("%b ", v[i])
	}
	sort.Slice(v, func(i, j int) bool { return v[i] > v[j] })
	var xorsum int64
	for _, v := range v {
		if v^xorsum < xorsum {
			fmt.Fprintln(w, "NO")
			return
		} else {
			xorsum ^= v
		}
	}
	fmt.Fprintln(w, "YES")
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
