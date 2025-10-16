// P1045 [NOIP 2003 普及组] 麦森数.go
package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strings"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var a int
	fmt.Fscan(r, &a)
	ans := new(big.Int)
	ans.Exp(big.NewInt(2), big.NewInt(int64(a)), nil)
	ans.Add(ans, big.NewInt(-1))
	b := ans.String()
	n := len(b)
	fmt.Fprintln(w, n)
	var t string
	if n >= 500 {
		t = b[n-500:]
	} else {
		t = strings.Repeat("0", 500-n) + b
	}
	for i := 0; i < 10; i++ {
		fmt.Fprintln(w, t[i*50:i*50+50])
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
