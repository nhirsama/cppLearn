#define LOCAL
//G1. Medium Demon Problem (easy version)
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int find(int arr[], int n){
    return arr[n] == n ? n : arr[n] = find(arr, arr[n]);
}
void Func(){
    int n;
    cin >> n;
    int root[n+5],next[n+5];
    for(int i=1;i<=n;i++){
        scanf("%d",&next[i]);

    }
}
int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
