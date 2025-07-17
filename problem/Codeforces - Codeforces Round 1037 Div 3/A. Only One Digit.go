// A. Only One Digit.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var s string
	fmt.Fscan(r, &s)
	var c int32 = '9'
	for _, v := range s {
		if c > v {
			c = v
		}
	}
	fmt.Fprintf(w, "%c\n", c)
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
