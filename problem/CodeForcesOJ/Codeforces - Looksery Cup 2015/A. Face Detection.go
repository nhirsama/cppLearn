// A. Face Detection.go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var n, m int64
	fmt.Fscan(r, &n, &m)
	sl := make([]string, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(r, &sl[i])
	}
	var ans int64
	for i := int64(0); i+1 < n; i++ {
		for j := int64(0); j+1 < m; j++ {
			var cnt int64 = 0
			dx := []int64{0, 0, 1, 1}
			dy := []int64{0, 1, 1, 0}
			base := "face"
			for k, _ := range base {
				for o := int64(0); o < 4; o++ {
					if sl[i+dx[o]][j+dy[o]] == base[k] {
						cnt++
						break
					}
				}
			}
			if cnt == 4 {
				ans++
			}
		}
	}
	fmt.Fprintln(w, ans)
}
func main() {
	var T = 1
	//fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
