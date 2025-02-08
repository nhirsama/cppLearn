//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
void Func(){
    int a[5];
    for(int i=0;i<4;i++) {
        cin>>a[i];
    }
    int ans  =0;
    for(int i=0;i<2;i++) {
        for(int j=2;j<4;j++) {
            if (a[i]>a[j] && a[1-i]>a[5-j]) ans++;
            else if (a[i]>a[j] && a[1-i] == a[5-j]) ans++;
        }
    }
    cout<<ans<<endl;
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
