//D
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i32 h, w;
    std::cin >> h >> w;
    std::vector<std::string> g(h);
    for (auto &i: g) std::cin >> i;
    i32 a, b, c, d;
    std::vector dist(h, std::vector<i32>(w, -1));
    std::cin >> a >> b >> c >> d;
    std::deque<pii> q;
    a--, b--, c--, d--;
    q.push_back(pii(a, b));
    i32 dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};
    i32 jmx[] = {1, 2, -1, -2, 0, 0, 0, 0}, jmy[] = {0, 0, 0, 0, 1, 2, -1, -2};
    dist[a][b] = 0;
    while (q.size()) {
        pii p = q.front();
        q.pop_front();
        if (p.first == c && p.second == d) {
            std::cout << dist[p.first][p.second] << endl;
            return;
        }
        for (i32 i = 0; i < 4; i++) {
            i32 ix = p.first + dx[i];
            i32 iy = p.second + dy[i];
            if (ix < 0 || ix >= h || iy < 0 || iy >= w) continue;
            if (dist[ix][iy] != -1 && dist[ix][iy] <= dist[p.first][p.second]) continue;
            if (g[ix][iy] == '#') continue;
            q.push_front(pii(ix, iy));
            dist[ix][iy] = dist[p.first][p.second];
        }
        for (i32 i = 0; i < 8; i++) {
            i32 ix = p.first + jmx[i];
            i32 iy = p.second + jmy[i];
            if (ix < 0 || ix >= h || iy < 0 || iy >= w) continue;
            if (dist[ix][iy] != -1 && dist[ix][iy] <= dist[p.first][p.second] + 1) continue;
            if (g[ix][iy] == '.') continue;
            q.push_back(pii(ix, iy));
            dist[ix][iy] = dist[p.first][p.second] + 1;
        }
    }
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        std::cin >> T;
    }

    while (T--) nhir();
    return 0;
}
