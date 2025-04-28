#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//int main()
//{
//	double shuzi = 6.0;
//	printf( "Hello World\n");
//	printf("%lf", shuzi);
//	scanf("%lf", &shuzi);
//	printf("%lf", shuzi);
//	return 0;
//
//
//}

//int main()
//{
//
//	printf("好想做爱");
//	return 0;
//
//}


//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	const int b = 5;
//	int arr[b] = { 0 };
//
//		return 0;
//
//}



//int main()
//{
//
//	char arr[] = "asdasdf";
//	char arr2[] = {
//
//		'q', 'd', 'c'
//
//	};
//	printf("%s\n%s\a\a\a\a\a\a\a\a", arr, arr2);
//	return 0;
//
//}



//int main()
//{
//	int input = 0;
//	printf("请输入你的数值：");
//	scanf("%d", &input);
//	printf("你输入的数值为：%d\n", input);
//	if (input == 5)
//	{
//		printf("123123");
//		input++;
//	}
//	else
//	{
//		int num = 0;
//		int num2 = 500;
//		while (input < 500)
//		{
//			printf("\a");
//			input++;
//			num++;
//			num2 = 500 - input;
//			printf("error声音已经响了%d次，还剩下%d次\n", num, num2);
//		}
//		printf("报错完成\n");
//	}
//	//scanf("%d", input)
//	return 0;
//}







//int main()
//{
//	double b = 23.5;
//	char c = 'a';   //字符型
//	printf("%c", c);
//	c = (char)b;
//	int a = 0;
//	a = ++a;
//	printf("%d\n", a);
//	printf("%d", c);
//	return 0;
//
//
//
//}





//pow(exponent, base)
//{
//	int base = 0, exponent = 0;
//
//	long long result = 1;
//
//	while (exponent != 0)
//	{
//		result *= base;
//		--exponent;
//	}
//	printf("结果：%lld", result);
//
//	return result;
//}





//int main()
//{
//	while (1)
//	{
//		char number2[64] = "0";
//		printf("请输入要转换为十进制的二进制数值：");
//		scanf("%s", &number2);
//		//printf("%s\n", number2);
//		int number10 = 0;
//		int numlong = sizeof(number2);
//		//printf("%d\n", numlong);
//		int one = 0;
//		int two = 0;
//		while (number2[one] != '\0')
//		{
//			++one;
//		}
//		//printf("%d\n", one);
//		while (one > 0)
//		{
//			one--;
//			int num = 0;
//			num = (int)number2[two] - 48;
//			//sscanf(&number2[two], "%d", &num);
//			int temp = pow(2, one) * num;
//			number10 = number10 + temp;
//			two++;
//		}
//		printf("转化后的十进制为：");
//		printf("%d\n", number10);
//		//number10 = number2;
//	}
//	return 0;
//}

/*
int main() {

	double a = 0.1;
	double b = 0.2;
	printf("%.20f", a + b);
	return 0;
}


int fuhao() {
	char aa[] = "1";
	char name[] = "Tobichi Origami";
	printf("%s\n%s", aa,name);
	return 0;
}
*/

#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}