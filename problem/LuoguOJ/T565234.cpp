#define LOCAL
//T565234 【MX-X8-T2】「TAOI-3」终有一天，飞向水平线的彼方
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
void Func(){
    int n;
    cin>>n;
    vector<int> a(n+5),b(n+5);
    for(int i=1;i<=n;i++){
       scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
      scanf("%d",&b[i]);
      a[i]-=b[i];
    }
    for(int i=1;i<=n;i++) {
        if (a[i]==0)continue;
        a[i+1]-=a[i];
        a[i]=0;
    }
    if (a[n+1] == 0)puts("Yes");
    else puts("No");
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
