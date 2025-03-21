//UVA1205 Color a Tree
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long
i64 n, r;

struct node {
    i64 root, size, sum;
    double w;
};

vector<node> g;

void nhir() {
    cin >> n >> r;
    while (n || r) {
        g.resize(n + 1);
        i64 ans = 0;
        for (i32 i = 1; i <= n; i++) {
            i32 x;
            cin >> x;
            g[i] = {0, 1, x, (double) x};
            ans += x;
        }
        i32 u, v;
        for (i32 i = 1; i < n; i++) {
            cin >> u >> v;
            g[v].root = u;
        }
        for (i32 i = 1; i < n; i++) {
            double vel = 0;
            i32 t = 0;
            for (i32 j = 1; j <= n; j++) {
                if (j != r && vel < g[j].w) {
                    t = j;
                    vel = g[j].w;
                }
            }
            i32 root = g[t].root;
            ans += g[t].sum * g[root].size;
            for (i32 j = 1; j <= n; ++j) {
                if (g[j].root == t) {
                    g[j].root = root;
                }
            }
            g[root].sum += g[t].sum;
            g[root].size += g[t].size;
            g[root].w = double(g[root].sum * 1.0 / g[root].size);
            g[t].w = -1;
        }
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
