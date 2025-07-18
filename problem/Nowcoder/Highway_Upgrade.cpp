//  Highway Upgrade
#include <bits/stdc++.h>

using int64 = int64_t;
using i64 = __int128;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

struct Point {
    i64 x;
    i64 y;

    Point() : x{0}, y{0} {}

    Point(i64 x_, i64 y_) : x{x_}, y{y_} {}
};

i64 dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

i64 cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

Point operator+(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

auto getHull(std::vector<Point> p) {
    std::sort(p.begin(), p.end(),
              [&](auto a, auto b) {
                  return a.x < b.x || (a.x == b.x && a.y < b.y);
              });

    std::vector<Point> hi, lo;
    for (auto p: p) {
        while (hi.size() > 1 && cross(hi.back() - hi[hi.size() - 2], p - hi.back()) >= 0) {
            hi.pop_back();
        }
        while (!hi.empty() && hi.back().x == p.x) {
            hi.pop_back();
        }
        hi.push_back(p);
        while (lo.size() > 1 && cross(lo.back() - lo[lo.size() - 2], p - lo.back()) <= 0) {
            lo.pop_back();
        }
        if (lo.empty() || lo.back().x < p.x) {
            lo.push_back(p);
        }
    }
    return std::make_pair(hi, lo);
}

const double inf = INFINITY;

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector gz(n, std::vector<std::array<i32, 2>>());
    std::vector gopp(n, std::vector<std::array<i32, 2>>());
    std::vector<std::array<i32, 4>> adj(m);
//    for (int i = 0; i < m; i++) {
//        std::cin >> adj[i][0] >> adj[i][1] >> adj[i][2] >> adj[i][3];
//        adj[i][0]--, adj[i][1]--;
//        gz[adj[i][0]].push_back({adj[i][1], adj[i][2]});
//        gopp[adj[i][1]].push_back({adj[i][0], adj[i][2]});
//    }
    for (auto &[u, v, t, w]: adj) {
        std::cin >> u >> v >> t >> w;
        u--, v--;
        gz[u].push_back({v, t});
        gopp[v].push_back({u, t});
    }
    auto digz = [&](i32 s = 0) {
        using pii = std::pair<i32, i32>;
        std::vector<i32> dij_dis(n, inf_i64);
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;
        q.emplace(0, s);
        dij_dis[s] = 0;
        std::vector<bool> dij_vis(n);
        while (!q.empty()) {
            i32 u = q.top().second;
            q.pop();
            if (dij_vis[u]) continue;
            dij_vis[u] = true;
            for (auto [v, w]: gz[u]) {
                if (dij_dis[v] > dij_dis[u] + w) {
                    dij_dis[v] = dij_dis[u] + w;
                    q.emplace(dij_dis[v], v);
                }
            }
        }
        return dij_dis;
    }(0);
    auto digopp = [&](i32 s = 0) {
        using pii = std::pair<i32, i32>;
        std::vector<i32> dij_dis(n, inf_i64);
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;
        q.emplace(0, s);
        dij_dis[s] = 0;
        std::vector<bool> dij_vis(n);
        while (!q.empty()) {
            i32 u = q.top().second;
            q.pop();
            if (dij_vis[u]) continue;
            dij_vis[u] = true;
            for (auto [v, w]: gopp[u]) {
                if (dij_dis[v] > dij_dis[u] + w) {
                    dij_dis[v] = dij_dis[u] + w;
                    q.emplace(dij_dis[v], v);
                }
            }
        }
        return dij_dis;
    }(n - 1);
    std::vector<Point> point(m);
    for (i32 i = 0; i < m; i++) {
        point[i] = Point(adj[i][3], digz[adj[i][0]] + digopp[adj[i][1]] + adj[i][2]);
    }
    auto [hi, lo] = getHull(point);
    i32 q;
    std::cin >> q;
    std::vector<std::array<int, 2>> query(q);
    for (i32 i = 0; i < q; i++) {
        query[i][1] = i;
        std::cin >> query[i][0];
    }
    std::ranges::sort(query, [](auto i, auto j) {
        return i[0] < j[0];
    });
    std::vector<i32> ans(q);
    for (int i = 0, j = 0; i < q; i++) {
        auto &[k, id] = query[i];
        while (j + 1 < (int) (lo.size()) && lo[j + 1].y - k * lo[j + 1].x <= lo[j].y - k * lo[j].x) j++;
        ans[id] = lo[j].y - k * lo[j].x;
    }
    for (auto i: ans) {
        std::cout << i << enld;
    }
//    for (; q--;) {
//        i32 k;
//        std::cin >> k;
//        i32 l = 0, r = lo.size() - 2;
//        auto eval = [&](i32 mid) {
//            return lo[mid].x - k * lo[mid].y;
//        };
//        while (l < r) {
//            i32 mid = (l + r) >> 1;
//            if (eval(mid) <= eval(mid + 1)) {
//                r = mid;
//            } else {
//                l = mid + 1;
//            }
//        }
//        std::cout << int64((lo[l].x - k * lo[l].y)) << endl;
//    }

//    for (i32 i = 0; i < m; i++) {
//        std::cout << dist[i] << ' ';
//    }
//    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}