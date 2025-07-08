// A. Rook.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var a, b int32
	fmt.Fscanf(r, "\n%c%c", &a, &b)
	for i := 'a'; i <= 'h'; i++ {
		for j := '1'; j <= '8'; j++ {
			if (a == i || b == j) && !(a == i && b == j) {
				fmt.Fprintf(w, "%c%c\n", i, j)
			}
		}
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
