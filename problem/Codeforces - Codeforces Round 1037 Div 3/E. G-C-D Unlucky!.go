// E. G-C-D Unlucky!.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
func nhir() {
	var n int
	fmt.Fscan(r, &n)
	p := make([]int64, n)
	s := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &p[i])
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &s[i])
	}

	for i := 1; i < n; i++ {
		if p[i-1]%p[i] != 0 {
			fmt.Fprintln(w, "NO")
			return
		}
	}

	for i := 1; i < n; i++ {
		if s[i]%s[i-1] != 0 {
			fmt.Fprintln(w, "NO")
			return
		}
	}

	if p[n-1] != s[0] {
		fmt.Fprintln(w, "NO")
		return
	}

	for i := 0; i < n; i++ {
		g := gcd(p[i], s[i])
		if i > 0 {
			if gcd(p[i-1]/p[i], s[i]/g) != 1 {
				fmt.Fprintln(w, "NO")
				return
			}
		}
		if i < n-1 {
			if gcd(s[i+1]/s[i], p[i]/g) != 1 {
				fmt.Fprintln(w, "NO")
				return
			}
		}
	}
	fmt.Fprintln(w, "YES")
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
