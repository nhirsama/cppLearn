//E. Triple Operations
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
void Func(){
    int l,r;
    cin>>l>>r;
    int ans = 0,aa = 1,pown = 0;
    bool flag = true;
    for (;aa<l;aa*=3,pown++) {
    }
    ans+=min(r-l+1,aa-l)*pown;
    for(;aa<r;aa*=3,pown++){
        if (l<aa/3) ans+=(aa-aa/3)*pown;
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
