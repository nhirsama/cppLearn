package main

/*
#include <stdio.h>
void Cmain(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",a+b);
}
*/
import "C"

func main() {
	C.Cmain()
}
