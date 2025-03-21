//UVA1205 Color a Tree
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

struct node {
    i64 w, cnt, yw;

    auto operator>(const node &b) const {
        return (1.0 * w / cnt) > (1.0 * b.w / b.cnt);
    }
};

void nhir() {
    i64 n, r;
    cin >> n >> r;
    while (n || r) {
        vector g(n + 1, vector<i32>());
        vector<node> point(n + 1);
        for (i32 i = 1; i <= n; i++) {
            cin >> point[i].yw;
            point[i].cnt = 1;
            point[i].w = point[i].yw;
        }
        for (i32 i = 1; i < n; i++) {
            i32 u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        auto dfs = [&](auto self, i32 u)-> void {
            for (auto i: g[u]) {
                self(self, i);
                point[u].w += point[i].w;
                point[u].cnt += point[i].cnt;
            }
        };
        dfs(dfs, r);
        i64 ans = 0, num = 1;
        auto dfs2 = [&](auto self, i32 u)-> void {
            ans += point[u].yw * num;
            num++;
            sort(g[u].begin(), g[u].end(), [&](i32 a, i32 b)-> bool { return point[a] > point[b]; });
            for (auto i: g[u]) {
                self(self, i);
            }
        };
        dfs2(dfs2, r);
        cout << ans << endl;
        cin >> n >> r;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }

    while (T--) nhir();
    return 0;
}
