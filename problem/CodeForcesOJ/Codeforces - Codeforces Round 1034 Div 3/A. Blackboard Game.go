// A. Blackboard Game.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var n int64
	fmt.Fscan(r, &n)
	if n%4 == 0 {
		fmt.Fprintln(w, "Bob")
	} else {
		fmt.Fprintln(w, "Alice")

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
