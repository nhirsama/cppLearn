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
    vector tree(n * k + 1, vector<i32>());
    for (int i = 1; i < n * k; i++) {
        i32 u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<i32> cnt(n * k + 1, 1);
    auto dfs = [&](auto &&self, i32 u, i32 root)-> void {
        i32 res = 0;
        for (auto v: tree[u]) {
            if (v == root) continue;
            self(self, v, u);
            cnt[u] += cnt[v];
            if (cnt[v]) res++;
        }
        if (cnt[u] < k && res >= 2) {
            cout << "No" << endl;
            exit(0);
        }
        if (cnt[u] > k || res >= 3) {
            cout << "No" << endl;
            exit(0);
        }
        if (cnt[u] == k) {
            cnt[u] = 0;
        }
    };
    dfs(dfs, 1, 0);
    cout << "Yes" << endl;
}

signed main() {
    i32 T;
    T = 1;
    // if (getenv("LOCAL") != nullptr) {
    //     freopen("Testlib.in", "r", stdin);
    //     // freopen("Code.out", "w", stdout);
    //     cin >> T;
    // }
    IOS;

    while (T--) nhir();
    return 0;
}
