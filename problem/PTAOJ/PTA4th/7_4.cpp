#include <bits/stdc++.h>
using i64 = long long;
using i32 = int;
using pii = std::pair<i32, i32>;

i64 gcdd(i64 a, i64 b) {
    if (a == 0 || b == 0)return std::max(a, b);
    return std::gcd(a, b);
}

struct data {
    i64 a, b;
    i64 cnt = 0;
};

void nhir() {
    i64 a, b;
    std::cin >> a >> b;
    std::queue<data> q;
    i64 ans = 1ll << 60;
    auto bfs = [&]() {
        q.push({a, b, 0});
        while (!q.empty()) {
            i64 x = q.front().a, y = q.front().b, z = q.front().cnt;
            q.pop();
            if (x == 0 && y == 0) {
                ans = std::min(ans, z);
                return;
            }
            i64 gcd = std::gcd(x, y);
            if (x >= gcd)q.push({x - gcd, y, z + 1});
            if (y >= gcd)q.push({x, y - gcd, z + 1});
        }
    };
    bfs();
    std::cout << ans << std::endl;
}

int main() {
    i32 t;
    std::cin >> t;
    while (t--) {
        nhir();
    }
    return 0;
}
