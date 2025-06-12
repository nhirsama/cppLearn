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

void nhir() {
    i32 x, y, k;
    std::cin >> x >> y >> k;
    while (std::gcd(x, y) != 1) {
        i32 g = std::gcd(x, y);
        x /= g;
        y /= g;
    }
    if (k < std::max(maxp[x], maxp[y])) {
        std::cout << -1 << endl;
        return;
    }
    auto bfs = [&](i32 t) {
        std::queue<pii> q;
        if (t == 1) return 0ll;
        q.push({1, 0});
        while (!q.empty()) {
            auto [xx,yy] = q.front();
            q.pop();
            for (int i = 2; i <= k; i++) {
                if (i * xx > t) break;
                if (t % (i * xx) == 0) {
                    if (i * xx == t) return yy + 1;
                    q.push({i * xx, yy + 1});
                }
            }
        }
        return -1ll;
    };
    std::cout << bfs(x) + bfs(y) << endl;
    // if (x == y) {
    //     std::cout << 0 << endl;
    //     return;
    // }
    // std::queue<pii> q;
    // std::set<i32> vis;
    // q.push({x, 0});
    // i32 gcd = std::gcd(x, y);
    // vis.insert(x);
    // while (!q.empty()) {
    //     auto [xx, yy] = q.front();
    //     q.pop();
    //     for (i32 i = 1; i <= gcd; i++) {
    //         i32 num = xx * i;
    //         if (num > 1e6) continue;
    //         if (num == y) {
    //             std::cout << yy + 1 << endl;
    //             return;
    //         }
    //         if (!vis.contains(num)) {
    //             vis.insert(num);
    //             q.push({num, yy + 1});
    //         }
    //     }
    //     for (i32 i = 1; i <= gcd; i++) {
    //         if (xx % i == 0) {
    //             i32 num = xx / i;
    //             if (num == y) {
    //                 std::cout << yy + 1 << endl;
    //                 return;
    //             }
    //             if (!vis.contains(num)) {
    //                 vis.insert(num);
    //                 q.push({num, yy + 1});
    //             }
    //         }
    //     }
    // }
    // std::cout << -1 << endl;
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
