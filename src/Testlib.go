package main

import (
	"fmt"
	"math"
)

var cnt int64
var m = map[float64]float64{}

func f(x float64) float64 {
	value, ok := m[x]
	if ok {
		cnt++
		return value
	}
	if x < 0 {
		return 1
	}
	m[x] = f(x-f(x-1)) / 2
	return m[x]
}
func main() {
	fmt.Printf("%f ", -math.Log2(f(0)))
	fmt.Printf("%d\n", cnt)
	cnt = 0
	fmt.Printf("%f ", -math.Log2(f(1)))
	fmt.Printf("%d\n", cnt)
	cnt = 0
	fmt.Printf("%f ", -math.Log2(f(2)))
	fmt.Printf("%d\n", cnt)
	cnt = 0
	fmt.Printf("%f ", -math.Log2(f(3)))
	fmt.Printf("%d\n", cnt)
	cnt = 0
	fmt.Printf("%f ", -math.Log2(f(4)))
	fmt.Printf("%d\n", cnt)
	cnt = 0
	fmt.Printf("%f ", -math.Log2(f(5)))

	//fmt.Printf("%f\n", -math.Log2(f(5)))

	dp := make([]int64, 15)
	cnt := make([]int64, 15)
	cnt[0] = 1
	for i := 0; i < 10; i++ {
		var j int64 = 1
		var k int64 = 1
		if i-1 >= 0 {
			cnt[i] += cnt[i-1]
			j = dp[i-1]
		}
		if k-j >= int64(0) {
			cnt[i] += cnt[k-j]
			k = dp[k-j]
		}
		dp[i] = k
	}
	fmt.Print(cnt)
}
