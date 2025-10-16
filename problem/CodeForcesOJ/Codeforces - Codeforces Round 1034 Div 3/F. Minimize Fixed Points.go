// F. Minimize Fixed Points.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var lpf = make([]int, 1e5+10)
var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func init() {
	for p := 2; p <= 1e5+3; p++ {
		if lpf[p] == 0 {
			for j := p; j <= 1e5+3; j += p {
				lpf[j] = p
			}
		}
	}
}

func nhir() {
	var n int
	fmt.Fscan(r, &n)
	mp := make(map[int][]int)
	for i := 2; i <= n; i++ {
		//pin := 0
		//t := i
		//for _, pr := range primes {
		//	for t%pr == 0 {
		//		pin = pr
		//		t /= pr
		//		if t == 1 || pr > t {
		//			break
		//		}
		//	}
		//	if t == 1 || pr > t {
		//		break
		//	}
		//}
		//if t > 1 {
		//	pin = t
		//}
		mp[lpf[i]] = append(mp[lpf[i]], i)
	}
	ans := make([]int, n+1)
	ans[1] = 1
	for _, v := range mp {
		//fmt.Fprint(w, t, v)
		for i := 0; i < len(v); i++ {
			ans[v[i]] = v[(i+1)%len(v)]
		}
	}
	for i := 1; i <= n; i++ {
		fmt.Fprintf(w, "%d ", ans[i])
	}
	fmt.Fprintln(w)
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
