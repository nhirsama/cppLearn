#define LOCAL
//P3386 【模板】二分图最大匹配
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> v[N];
int n,m,e,mch[N];
bool st[N];
bool find(int x){
    for(auto y:v[x]){
        if(st[y]) continue;
        st[y] = true;
        if(mch[y]== 0 || find(mch[y])){
            mch[y] = x;
            return true;
        }
    }
    return false;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> m >> e;
    for (int i = 1; i <= e; i++) {
        int x,y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(st, 0, sizeof(st));
        if(find(i)) ans++;
    }
    cout << ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}