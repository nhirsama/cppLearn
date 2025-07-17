// D. This Is the Last Time.go
package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"sort"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)

type kyan struct {
	l, r, re int
}

type KyanPriority_queue []kyan

func (h *KyanPriority_queue) Len() int {
	return len(*h)
}

func (h *KyanPriority_queue) Less(i, j int) bool {
	return (*h)[i].re > (*h)[j].re // 大根堆
}

func (h *KyanPriority_queue) Swap(i, j int) {
	(*h)[i], (*h)[j] = (*h)[j], (*h)[i]
}

func (h *KyanPriority_queue) Push(x interface{}) {
	*h = append(*h, x.(kyan))
}

func (h *KyanPriority_queue) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}

func nhir() {
	var n, k int
	fmt.Fscan(r, &n, &k)
	v := make([]kyan, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &v[i].l, &v[i].r, &v[i].re)
	}
	sort.Slice(v, func(i, j int) bool { return v[i].l < v[j].l })
	h := &KyanPriority_queue{}
	heap.Init(h)
	p := 0
	for {
		for p < n && v[p].l <= k {
			heap.Push(h, v[p])
			p++
		}
		if h.Len() == 0 {
			break
		}
		top := heap.Pop(h).(kyan).re

		if top <= k {
			break
		}
		k = top
	}
	fmt.Fprintln(w, k)
}
func main() {
	var T = 1
	fmt.Fscan(r, &T)
	for _i := 0; _i < T; _i++ {
		nhir()
	}
	defer w.Flush()
}
