// B. Maximum Multiple Sum.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	n := 0
	fmt.Fscan(r, &n)
	if n == 3 {
		fmt.Fprintln(w, 3)
	} else {
		fmt.Fprintln(w, 2)
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
