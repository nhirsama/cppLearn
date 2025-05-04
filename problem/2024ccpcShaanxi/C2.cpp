#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::vector;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n << 1 | 1), site(n << 1 | 1);
    vector<bool> changed(n + 1), still(n << 1 | 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == i) still[i] = true;
    }
    ll ans = 0;

    auto dfs = [&](auto &&self, int now, int tar)-> ll {
        if (now == 0) return 1;
        ll res = 0;
        changed[now] = true;
        if (!still[tar]) {
            res += self(self, tar, a[tar]);
        } else still[now] = true;
        if (res == 0) changed[now] = false;
        else {
            changed[now] = true;
            ++res;
        }
        return res;
    };

    for (int i = 1; i <= n; ++i) {
        if (!changed[i]&&!still[a[i]])
            ans += dfs(dfs, i, a[i]);
    }
    cout << ans;
}
