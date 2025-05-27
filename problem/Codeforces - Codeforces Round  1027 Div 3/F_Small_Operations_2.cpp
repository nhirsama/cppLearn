//  F. Small Operations
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'
using pii = std::array<i32, 2>;
std::vector<int> maxp, primes;

void sieve(int n) {
    maxp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (maxp[i] == 0) {
            maxp[i] = i;
            primes.push_back(i);
        }
        for (int p: primes) {
            if (i * p > n) break;
            maxp[i * p] = std::max(p, maxp[i]);
            if (p == maxp[i]) break;
        }
    }
}

constexpr i32 inf = 0x3f3f3f3f;

void nhir() {
    i32 x, y, k;
    std::cin >> x >> y >> k;
    while (std::gcd(x, y) != 1) {
        i32 gcd = std::gcd(x, y);
        x /= gcd;
        y /= gcd;
    }
    if (k < std::max(maxp[x], maxp[y])) {
        std::cout << -1 << endl;
        return;
    }
    auto fun = [&k](i32 t) {
        std::vector<pii> ys;
        for (i32 i = 0; primes[i] <= t; i++) {
            i32 cnt = 0;
            while (t % primes[i] == 0) {
                cnt++;
                t /= primes[i];
            }
            if (cnt) ys.push_back({primes[i], cnt});
        }
        std::vector<i32> yss;
        auto dfs = [&](this auto self, i32 cnt, i32 num)-> void {
            if (cnt >= ys.size()) {
                yss.push_back(num);
                return;
            }
            for (i32 i = 0, pp = num; i <= ys[cnt][1]; i++, pp *= ys[cnt][0]) {
                self(cnt + 1, pp);
            }
        };
        dfs(0, 1);
        std::ranges::sort(yss);
        // for (auto i: yss) std::cout << i << ' ';
        // std::cout.flush();
        auto dijkstra = [&yss,&k](i32 s = 0) {
            i32 n = yss.size();
            using pii = std::pair<i32, i32>;
            std::vector<i32> dij_dis(n, 0x3f3f3f3f);
            std::priority_queue<pii, std::vector<pii>, std::greater<> > q;
            q.emplace(0, s);
            dij_dis[s] = 0;
            while (!q.empty()) {
                i32 u = q.top().second;
                q.pop();
                for (i32 i = u + 1; i < n; i++) {
                    if (yss[i] % yss[u] == 0) {
                        if (yss[i] / yss[u] > k) continue;
                        if (dij_dis[i] > dij_dis[u] + 1) {
                            dij_dis[i] = dij_dis[u] + 1;
                            q.emplace(dij_dis[i], i);
                        }
                    }
                }
            }
            return dij_dis;
        };
        auto dis = dijkstra();
        return dis[yss.size() - 1];
    };
    std::cout << fun(x) + fun(y) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    sieve(1e6 + 500);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
