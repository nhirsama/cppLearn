// Another Day of Sun.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

const mod = 998244353

func nhir() {
	var n int64
	fmt.Fscan(r, &n)
	v := make([]int64, n)
	for i := 0; i < int(n); i++ {
		fmt.Fscan(r, &v[i])
	}
	dp := make([][2]int64, n+1)
	dp2 := make([][2]int64, n+1)
	//var pow2 int64 = 1
	//dp2 := make([][2]int64, n+1)
	//dp[0][0] = 1
	//for i := n - 1; i >= 0; i-- {
	//	if v[i] == 1 {
	//		dp[i][1] = dp[i+1][1] + dp[i+1][0] + 1
	//	} else if v[i] == 0 {
	//		dp[i][0] = dp[i+1][0] + dp[i+1][1]
	//	} else {
	//		if i == n-1 {
	//			dp[i][1]++
	//		}
	//		dp[i][1] += dp[i+1][0] + dp[i+1][1]
	//		dp[i][0] = dp[i+1][0] + dp[i+1][1]
	//		pow2 *= 2
	//	}
	//	//pow2 *= 2
	//}
	dp[0][0], dp[0][1] = 1, 0
	for i := 0; i < int(n); i++ {
		if v[i] == 1 {
			dp[i+1][1] = (dp[i][1] + dp[i][0]) % mod
			dp2[i+1][1] = (dp2[i][1] + dp2[i][0] + dp[i][0]) % mod
		} else if v[i] == 0 {
			dp[i+1][0] = (dp[i][0] + dp[i][1]) % mod
			dp2[i+1][0] = (dp2[i][1] + dp2[i][0]) % mod
		} else {
			dp[i+1][1] = (dp[i][0] + dp[i][1]) % mod
			dp[i+1][0] = (dp[i][0] + dp[i][1]) % mod

			dp2[i+1][0] = (dp2[i][1] + dp2[i][0]) % mod
			dp2[i+1][1] = (dp2[i][1] + dp2[i][0] + dp[i][0]) % mod
		}
	}
	//fmt.Fprintln(w, dp2)
	fmt.Fprintln(w, (dp2[n][0]+dp2[n][1])%mod)
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
