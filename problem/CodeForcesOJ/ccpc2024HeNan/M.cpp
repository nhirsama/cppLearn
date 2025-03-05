#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> ai(n + 1), bi(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ai[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> bi[i];
    }
    int l = 0, r = 1e9;
    auto check = [&](ll mid)-> bool {
        ll minn = 0, maxn = 1e9;
        for (int i = 1; i <= n; i++) {
            minn = max(minn, ai[i] - mid * bi[i]);
            maxn = min(maxn, ai[i] + mid * bi[i]);
        }
        return minn <= maxn;
    };
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
