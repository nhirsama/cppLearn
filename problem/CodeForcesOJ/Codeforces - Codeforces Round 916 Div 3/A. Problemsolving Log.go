// A. Problemsolving Log.go
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
	var cnt int
	var mp = make(map[int32]int32)
	for _, i := range s {
		mp[i]++
	}
	for v, k := range mp {
		if k >= (v-'A')+1 {
			cnt++
		}
	}
	fmt.Fprintln(w, cnt)
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
