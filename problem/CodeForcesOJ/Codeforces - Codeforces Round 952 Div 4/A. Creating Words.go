// A. Creating Words.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var a, b string
	fmt.Fscan(r, &a, &b)
	t := a[:1]
	a = b[:1] + a[1:]
	b = t + b[1:]
	fmt.Fprintln(w, a, b)
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
