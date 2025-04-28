/*
//测试vs是否支持使用变量定义数组，经测试vs必须使用常量定义数组。
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
*/
#include <iostream>
using namespace std;
int aaa;
int main() {
    std::cin >> aaa;
    for (int i = 0; i <= aaa;i++) {
        cout << i << ' ';
    }
    return 0;
}

