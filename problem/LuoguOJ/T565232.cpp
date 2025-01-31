#define LOCAL
//T565232 【MX-X8-T0】「TAOI-3」分数
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n,t;
    cin >> n>>t;
    long long ans = 0;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
      ans+=v[i];
    }
    if (ans >= t) {
      ans = 0;
      for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        ans+=a;
      }
    }
    cout << ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
