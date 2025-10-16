// C. Manhattan Pairs.go
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

type point struct{ x, y, id int64 }

func nhir() {
	var n int
	fmt.Fscan(r, &n)
	v := make([]point, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &v[i].x, &v[i].y)
		v[i].id = int64(i)
	}
	sort.Slice(v, func(i, j int) bool {
		if v[i].x == v[j].x {
			return v[i].y < v[j].y
		}
		return v[i].x < v[j].x
	})
	sort.Slice(v[:n/2], func(i, j int) bool {
		return v[i].y < v[j].y
	})
	sort.Slice(v[n/2:n], func(i, j int) bool {
		return v[i+n/2].y > v[j+n/2].y
	})
	for i := 0; i < n/2; i++ {
		fmt.Fprintf(w, "%d %d\n", v[i].id+1, v[i+n/2].id+1)
	}
	//fmt.Fprint(w, v)
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
