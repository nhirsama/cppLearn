#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::pair;

using ll = long long;
using PII = pair<int, int>;

constexpr bool more = false;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    std::map<int, vector<int> > idxs;
    for (auto &x: a) cin >> x;
    for (int i = 0; i < n; ++i) {
        idxs[a[i]].emplace_back(i);
    }
    std::map<PII, ll> me;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (me.count({x, y})) {
            cout << me[{x, y}] << "\n";
            continue;
        }
        if (idxs.count(x) == 0 || idxs.count(y) == 0) {
            cout << 0 << "\n";
            continue;
        }
        if (x == y) {
            ll sum = idxs[x].size();
            std::cout << sum * (sum - 1) / 2 << '\n';
            continue;
        }
        auto &idxx = idxs[x], &idxy = idxs[y];
        // int i = -1;
        ll ans = 0;
        // for (int j = 0; j < idxy.size(); ++j) {
        //     while (i + 1 < idxx.size() && idxy[j] > idxx[i + 1])
        //         ++i;
        //     ans += i + 1;
        // }
        if (idxx.size() < idxy.size()) {
            for (auto t: idxx) {
                ans += idxy.size() - (std::lower_bound(idxy.begin(), idxy.end(), t) - idxy.begin());
            }
        } else {
            for (auto t: idxy) {
                ans += (std::lower_bound(idxx.begin(), idxx.end(), t) - idxx.begin());
            }
        }
        // me[{x, y}] = ans;
        cout << ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (more)
        std::cin >> T;
    while (T--) {
        solve();
    }
}
