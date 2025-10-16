// C. Good Prefixes.go
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
	v := make([]int, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(r, &v[i])
	}
	var sum, ma, ans int64
	for i := int64(0); i < n; i++ {
		sum += int64(v[i])
		ma = max(ma, int64(v[i]))
		if sum-ma == ma {
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
