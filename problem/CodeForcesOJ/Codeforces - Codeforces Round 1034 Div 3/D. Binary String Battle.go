// D. Binary String Battle.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var n, k int64
	fmt.Fscan(r, &n, &k)
	var s string
	fmt.Fscan(r, &s)
	var cnt int64
	for _, v := range s {
		if v == '1' {
			cnt++
		}
	}
	if cnt <= k {
		fmt.Fprintln(w, "Alice")
		return
	}
	dp := make([]int64, n+1)
	if k > n/2 {
		for i := int64(0); i < n; i++ {
			if s[i] == '1' {
				dp[i+1]++
			}
			dp[i+1] += dp[i]
		}
		var maxv int64
		for i := int64(0); i < n-k; i++ {
			maxv = max(maxv, dp[i+k]-dp[i])
		}
		if maxv <= k {
			fmt.Fprintln(w, "Alice")
			return
		}
	}
	fmt.Fprintln(w, "Bob")
	//var cnt, tot int64
	//t := make([]int64, 0)
	//for _, i := range s {
	//	if i == '1' {
	//		tot++
	//		cnt++
	//	} else {
	//		t = append(t, tot)
	//		tot = 0
	//	}
	//}
	//t = append(t, tot)
	//fmt.Fprint(w, t)
	//for _, v := range t {
	//	if v >= k && cnt > k {
	//		fmt.Fprintln(w, "Bob")
	//		return
	//	}
	//}
	//fmt.Fprintln(w, "Alice")
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
