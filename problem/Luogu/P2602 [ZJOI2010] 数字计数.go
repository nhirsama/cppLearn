// P2602 [ZJOI2010] 数字计数.go
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

var dp [20]int64
var pow [20]int64

func init() {
	pow[0] = 1
	for i := 0; i < 15; i++ {
		pow[i+1] = pow[i] * 10
		dp[i+1] = dp[i]*10 + pow[i]
	}
}

func nhir() {
	var l, rr int64
	fmt.Fscan(r, &l, &rr)

	var get = func(a int64) (ans [10]int64) {
		var tos = strconv.FormatInt(a, 10)
		var n = len(tos)
		for i, bit := range tos {
			for j := 0; j < 10; j++ {
				ans[j] += dp[n-i-1] * int64(bit-'0')
			}
			for j := int32(0); j < bit-'0'; j++ {
				ans[j] += pow[n-i-1]
			}
			a -= pow[n-i-1] * (int64(bit - '0'))
			ans[bit-'0'] += a + 1
			ans[0] -= pow[n-i-1]
		}
		return
	}
	ansl := get(l - 1)
	ansr := get(rr)
	for i := 0; i < 10; i++ {
		fmt.Fprintf(w, "%d ", ansr[i]-ansl[i])
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
