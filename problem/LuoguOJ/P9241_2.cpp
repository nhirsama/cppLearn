//P9241 [蓝桥杯 2023 省 B] 飞机降落
//暴力杯，启动
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    auto solve = []() {
        ll n;
        cin >> n;

        struct node {
            ll t, d, l;
        };
        vector<node> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].t >> arr[i].d >> arr[i].l;
        }
        vector<bool> st(n);
        bool flag = false;
        auto dfs = [&](auto self, int t, int m) {
            if (m == n) {
                cout << "YES" << endl;
                flag = true;
                return;
            }
            for (int i = 0; i < n; i++) {
                int tt = t;
                if (st[i])continue;
                if (tt > arr[i].t + arr[i].d)continue;
                if (tt < arr[i].t) tt = arr[i].t;
                st[i] = true;
                self(self, tt + arr[i].l, m + 1);
                if (flag)return;
                st[i] = false;
            }
        };
        dfs(dfs, 0, 0);
        if (flag)return;
        cout << "NO" << endl;
    };
    while (t--) {
        solve();
    }
    return 0;
}
