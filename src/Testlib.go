package main

/*
#include <stdio.h>
void main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",a+b);
}
*/
import "C"

func main() {
	C.main()
}
