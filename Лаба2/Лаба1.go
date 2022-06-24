package main

import (
	"fmt"
)

func main() {
	var a, b, c, s, v int
	fmt.Print("a=")
	fmt.Scan(&a)
	fmt.Print("b=")
	fmt.Scan(&b)
	fmt.Print("c=")
	fmt.Scan(&c)
	s = a * b * c
	v = 2 * (a*b + b*c + a*c)
	fmt.Print("s=")
	fmt.Println(s)
	fmt.Print("v=")
	fmt.Println(v)
}
