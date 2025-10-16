// F. 1-1-1 Free Tree!.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var n, q int
	fmt.Fscan(r, &n, &q)
	cl := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &cl[i])
	}
	tr := make([][][2]int, n)
	var sumd int64
	for i := 1; i < n; i++ {
		var u, v, c int
		fmt.Fscan(r, &u, &v, &c)
		u--
		v--
		tr[u] = append(tr[u], [2]int{v, c})
		tr[v] = append(tr[v], [2]int{u, c})
		//if cl[u] != cl[v] {
		//	sumd += int64(c)
		//}
	}
	f := make([]int, n)
	po := make([]int, n)
	f[0], po[0] = -1, 0
	stack := []int{0}
	for len(stack) > 0 {
		u := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		for _, nei := range tr[u] {
			v, wgt := nei[0], nei[1]
			if v == f[u] {
				continue
			}
			f[v], po[v] = u, wgt
			stack = append(stack, v)
		}
	}
	//var dfs func(u, fa int)
	//dfs = func(u, fa int) {
	//	for _, i := range tr[u] {
	//		if i[0] == fa {
	//			continue
	//		}
	//		f[i[0]] = u
	//		po[i[0]] = i[1]
	//		dfs(i[0], u)
	//	}
	//}
	//dfs(0, -1)
	m := make([]map[int]int64, n)
	sum := make([]int64, n)
	//m[0] = make(map[int]int64)
	for i := 0; i < n; i++ {
		m[i] = make(map[int]int64)
	}
	for i := 1; i < n; i++ {
		//m[i] = make(map[int]int64)
		sum[f[i]] += int64(po[i])
		m[f[i]][cl[i]] += int64(po[i])
		if cl[i] != cl[f[i]] {
			sumd += int64(po[i])
		}
		//if cl[i] != cl[f[i]] {
		//	sumd += int64(po[i])
		//}
		//sum[i] += int64(po[i])
		//m[i][cl[i]] += int64(po[i])
	}
	for q > 0 {
		q--
		var u, x int
		fmt.Fscan(r, &u, &x)
		u--
		if cl[u] == x {
			fmt.Fprintln(w, sumd)
			continue
		}
		sumd -= sum[u]
		sumd += m[u][cl[u]]
		if f[u] != -1 {
			if cl[u] != cl[f[u]] {
				sumd -= int64(po[u])
			}
			m[f[u]][cl[u]] -= int64(po[u])
		}
		//sumd -= int64(po[u])
		//m[f[u]][cl[u]] -= int64(po[u])
		cl[u] = x
		if f[u] != -1 {
			m[f[u]][x] += int64(po[u])
			if x != cl[f[u]] {
				sumd += int64(po[u])
			}
		}
		//if x != cl[f[u]] {
		//	sumd += int64(po[u])
		//}
		//m[f[u]][x] += int64(po[u])
		sumd += sum[u]
		sumd -= m[u][x]
		fmt.Fprintln(w, sumd)
	}
	//qz := make([]bool, n)
	//sqn := int(math.Sqrt(float64(n)))
	//for i := 0; i < n; i++ {
	//	if len(tr[i]) > sqn {
	//		qz[i] = true
	//	}
	//}
	//for q > 0 {
	//	q--
	//	var u, x int
	//	fmt.Fscan(r, &u, &x)
	//	u--
	//	if x == cl[u] {
	//		fmt.Fprintln(w, sumd)
	//		continue
	//	}
	//	if qz[u] {
	//		sumd += sumcl[u][cl[u]] - sumcl[u][x]
	//	}
	//	for _, t := range tr[u] {
	//		if cl[u] != cl[t[0]] {
	//			sumd -= int64(t[1])
	//		}
	//		if x != cl[t[0]] {
	//			sumd += int64(t[1])
	//		}
	//	}
	//	cl[u] = x
	//	fmt.Fprintln(w, sumd)
	//}
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
