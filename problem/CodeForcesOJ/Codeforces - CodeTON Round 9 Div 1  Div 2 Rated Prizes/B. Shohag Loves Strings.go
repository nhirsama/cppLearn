// B. Shohag Loves Strings.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var s string
	fmt.Fscan(r, &s)
	for i, _ := range s {
		if i >= 1 {
			if s[i] == s[i-1] {
				fmt.Fprintln(w, s[i-1:i+1])
				return
			}
		}
		if i >= 2 {
			if s[i-1] != s[i] && s[i-2] != s[i-1] && s[i-2] != s[i] {
				fmt.Fprintln(w, s[i-2:i+1])
				return
			}
		}
	}
	fmt.Fprintln(w, -1)
	//if len(s) > 1 {
	//	fmt.Fprintln(w, s[0:2])
	//} else {
	//	fmt.Fprintln(w, -1)
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
