// B. Line Segments.go
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"slices"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

func nhir() {
	var a, ax, ay, bx, by int
	fmt.Fscan(r, &a, &ax, &ay, &bx, &by)
	var v []int = make([]int, a)
	var ans int
	for i := 0; i < a; i++ {
		fmt.Fscan(r, &v[i])
		ans += v[i]
	}
	if a == 1 {
		if (ax-bx)*(ax-bx)+(ay-by)*(ay-by) == ans*ans {
			fmt.Fprintln(w, "YES")
			return
		} else {
			fmt.Fprintln(w, "NO")
			return
		}
	}
	var maxv = slices.Max(v)
	var polen = (ax-bx)*(ax-bx) + (ay-by)*(ay-by)
	if (ax-bx)*(ax-bx)+(ay-by)*(ay-by) == 0 && a <= 2 {
		if a == 2 {
			//for i, _ := range v {
			//	if i >= 1 {
			//		if v[i] != v[i-1] {
			//			fmt.Fprintln(w, "NO")
			//			return
			//		}
			//	}
			//}
			if v[0] == v[1] {
				fmt.Fprintln(w, "YES")
			} else {
				fmt.Fprintln(w, "NO")
			}
			return
		} else {
			fmt.Fprintln(w, "NO")
			return
		}
	} else if ans*ans >= (ax-bx)*(ax-bx)+(ay-by)*(ay-by) && math.Sqrt(float64(polen))+float64(ans-maxv) >= float64(maxv) {
		fmt.Fprintln(w, "YES")
	} else {
		fmt.Fprintln(w, "NO")
	}

}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
