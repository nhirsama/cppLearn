package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var n, m int64
	fmt.Fscan(r, &n, &m)
	if n < m {
		fmt.Fprintln(w, "No")
	} else if (n-m)%2 == 1 {
		fmt.Fprintln(w, "No")
	} else {
		fmt.Fprintln(w, "Yes")
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
