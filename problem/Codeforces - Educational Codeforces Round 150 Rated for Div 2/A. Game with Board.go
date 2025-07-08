// A. Game with Board.go
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
	if n >= 5 {
		fmt.Fprintln(w, "Alice")
	} else {
		fmt.Fprintln(w, "Bob")
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
