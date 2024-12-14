//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
queue<pair<pair<int,int>, int> > q;
int dfs(long long n) {
    q = queue<pair<pair<int,int>, int> >();
    int m = 0;
    q.push(make_pair(make_pair(m,n), 0));
    while (!q.empty()) {
        pair<pair<int,int>, int> p = q.front();
        q.pop();
        m = p.first.first;
        n = p.first.second;
        if (m == n){
            return p.second;
        }
        m++;
        int aa = gcd(m, n);
        int m1=m/aa;
        int n1=n/aa;
        q.push(make_pair(make_pair(m1,n1), p.second+1));
        n++;
        aa = gcd(m, n);
        m1=m/aa;
        n1=n/aa;
        q.push(make_pair(make_pair(m1,n1), p.second+1));
    }
return 0;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int ans = 0;
    for (long long i = 1; i <= n; i++) {
        ans+=dfs(i);
    }
    cout << ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}