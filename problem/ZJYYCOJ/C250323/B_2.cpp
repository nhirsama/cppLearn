//模板
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i64, i64> pii;
constexpr int N = 1e5 + 10;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()

struct point {
    i32 x,y;
    i64 dist;
};

void nhir() {
    i64 n;
    std::cin >> n;
    std::vector<pii> v(n + 1);
    std::vector<i32> ans;
    std::vector<point> dist;
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i].x >> v[i].y;
    }
    for (i32 i = 1; i <= n; i++) {
        for (i32 j = i + 1; j <= n; j++) {
            i64 xx = v[i].x - v[j].x;
            i64 yy = v[i].y - v[j].y;
            dist.push_back({i, j, xx * xx + yy * yy});
        }
    }
    std::sort(dist.begin(), dist.end(), [](point a, point b) { return a.dist > b.dist; });
    std::vector<bool> st(n + 1);
    i32 cnt = 0;
    for (auto i: dist) {
        if (st[i.x] || st[i.y]) continue;
        else {
            st[i.x] = true;
            st[i.y] = true;
            cnt += 2;
        }
    }
    if (st[1] == false && cnt == n - 1) {
        std::cout << "NO\n";
    } else std::cout << "YES\n";
}

signed main() {
    IOS;
    i32 T;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
