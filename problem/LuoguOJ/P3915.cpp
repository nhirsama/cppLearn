//P3915 树的分解
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
    vector tree(n + 1, vector<i32>());
    for (int i = 1; i < n; i++) {
        i32 u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<i32> cnt(n + 1);
    auto dfs = [&](auto &&self, i32 u, i32 root)-> void {
        for (auto v: tree[u]) {
            if (v == root) continue;
            self(self, v, u);
            if (cnt[v] == k) cnt[v] = 0;
            cnt[u] += cnt[v];
        }
        cnt[u]++;
    };
    dfs(dfs, 1, 0);
    if (cnt[1] == k) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
}

signed main() {
    ;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
