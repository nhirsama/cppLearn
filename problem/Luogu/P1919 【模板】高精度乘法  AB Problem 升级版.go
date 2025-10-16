// P1919 【模板】高精度乘法  AB Problem 升级版.go
package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var a, b string
	fmt.Fscan(r, &a, &b)
	x := new(big.Int)
	x.SetString(a, 10)
	y := new(big.Int)
	y.SetString(b, 10)
	x = x.Mul(x, y)
	fmt.Println(x)
}
func main() {
	var T = 1
	//fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
