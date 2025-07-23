// P2657 [SCOI2009] windy 数.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var l, rr int64
	fmt.Fscan(r, &l, &rr)

	var get = func(n int64) {

	}
}
func main() {
	var T = 1
	//fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
