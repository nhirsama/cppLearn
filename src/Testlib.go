package main

import (
	"fmt"
)

func main() {
	var s string = "籗籘籝籨籌籑籒籗籎籜籎籨籪籽籨籊籕籕"
	for _, b := range s {
		fmt.Printf("%c", b-0x7c00-9)
	}
}
