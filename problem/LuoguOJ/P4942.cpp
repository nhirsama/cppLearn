#define LOCAL
//P4942 小凯的数字
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int Q;
    cin >> Q;
    while(Q--){
        long long l,r;
        scanf("%lld%lld",&l,&r);
        __int128_t ll = l,rr = r;
        __int128_t llll=1;
        __int128_t ans = llll*(rr+ll)*(rr-ll+1)/2%9;
        cout<<static_cast<int>(ans)%9<<endl;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}