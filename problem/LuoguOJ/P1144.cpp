//P1144 最短路计数
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
constexpr i32 mod = 100003;
void nhir() {
    i64 n, m;
    cin >> n >> m;
    vector g(n + 1, vector<i32>());
    for (i32 i = 1; i <= m; i++) {
        i32 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<i32> dis(n + 1, 1E18);
    vector<i32> cnt(n+1);
    auto dijkstra = [&](int s = 1) -> void {
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII> > q;
        q.emplace(0, s);
        dis[s] = 0;
        vector<int> vis(n + 1);
        cnt[s] =  1;
        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (vis[x]) continue;
            vis[x] = 1;
            for (auto y: g[x]) {
                if (dis[y] > dis[x] + 1) {
                    dis[y] = dis[x] + 1;
                    cnt[y] = cnt[x];
                    q.emplace(dis[y], y);
                }
                else if (dis[y] == dis[x]+1) {
                    cnt[y]+=cnt[x];
                    cnt[y]%=mod;
                }
            }
        }
    };
    dijkstra(1);
    for (i32 i = 1;i<=n;i++) {
        cout<<cnt[i]<<endl;
    }
}

signed main() {
    ;
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }

    while (T--) nhir();
    return 0;
}
