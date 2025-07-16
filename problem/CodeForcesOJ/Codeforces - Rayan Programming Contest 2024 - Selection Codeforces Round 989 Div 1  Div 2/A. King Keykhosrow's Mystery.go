// A. King Keykhosrow's Mystery.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var a, b int64
	fmt.Fscan(r, &a, &b)
	fmt.Fprintln(w, a*b/gcd(a, b))
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
