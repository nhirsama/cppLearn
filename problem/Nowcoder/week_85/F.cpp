//模板
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

void nhir() {
    i32 n, k;
    cin >> n >> k;
    vector g(n + 1, vector<i32>());
    for (i32 i = 1; i < n; i++) {
        i32 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    i32 l = 0, r = n;
    auto check = [&](i32 mid) {
        vector<i32> cnt(n + 1);
        i32 need = 0;
        auto dfs = [&](auto &&self, i32 u, i32 root)-> void {
            for (auto &i: g[u]) {
                if (i == root) continue;
                self(self, i, u);
                cnt[u] += cnt[i];
            }
            if (cnt[u] + 1 > mid) {
                need++;
                cnt[u] = 0;
            } else cnt[u]++;
        };
        dfs(dfs, 1, 0);
        return need <= k;
    };
    while (l < r) {
        i32 mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

signed main() {
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        T = 3;
    }
    IOS;
    while (T--) nhir();
    return 0;
}
