#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


/*
int main()
{
	fbnq();
	return 0;
}
*/


int fbnq(){

	int years = 0;
	int amount_1 = 1;
	int amount_2 = 0;
	int amount_3 = 0;
	int amount_4 = 0;
	scanf("%d", &years);
	while (years > 0)
	{
		years--;
		amount_1 = amount_1 + amount_2;
		amount_2 = amount_3;
		amount_3 = amount_4;
		amount_4 = amount_1;
	}
	amount_1 = amount_1 + amount_2 + amount_3 + amount_4;
	printf("%d", amount_1);

	return 0;

}