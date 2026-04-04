// B_Simply_Sitting_on_Chairs.go
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
	v := make([]int64, n)
	for i, _ := range v {
		fmt.Fscan(r, &v[i])
	}
	var ans int64
	for i, j := range v {
		if j <= int64(i+1) {
			ans++
		}
	}
	fmt.Fprintln(w, ans)
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
