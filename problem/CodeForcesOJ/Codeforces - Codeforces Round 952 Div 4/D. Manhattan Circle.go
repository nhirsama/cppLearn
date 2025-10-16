// D. Manhattan Circle.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var n, m int
	fmt.Fscan(r, &n, &m)
	v := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &v[i])
	}
	h := make([]int, n)
	l := make([]int, m)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if v[i][j] == '#' {
				h[i]++
				l[j]++
			}
		}
	}
	var ansx, ansy int
	for i := 0; i < n; i++ {
		if h[i] > h[ansx] {
			ansx = i
		}
	}
	for i := 0; i < m; i++ {
		if l[i] > l[ansy] {
			ansy = i
		}
	}
	fmt.Fprintln(w, ansx+1, ansy+1)
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
