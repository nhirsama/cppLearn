//P6364 [传智杯 #2 初赛] 1024 程序员节发橙子
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
int arr[1000010];
int Num[1000010];
int main() {
#define cin fin
#define cout fout
    ifstream fin("Testlib.in");
    ofstream fout("Code.out");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      //cin >> arr[i];
        scanf("%d",arr+i);
    }
    Num[0] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) Num[i] += Num[i-1]+1;
        else if (arr[i] < arr[i-1]) Num[i] = 1;
        else Num[i] = Num[i-1];
    }
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > arr[i+1]) Num[i] = max(Num[i],Num[i+1]+1);
        else if (arr[i] < arr[i+1]) Num[i] = max(Num[i],1);
        else Num[i] = max(Num[i+1],Num[i]);
    }
    long long ans = 0;
    for (int i = 0;i<n;i++) ans+=Num[i];
    cout << ans << endl;
    return 0;
}