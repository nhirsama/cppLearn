#define LOCAL
//P3372 【模板】线段树 1
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long int arr[N],n,m,tree[N];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
    }


#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}