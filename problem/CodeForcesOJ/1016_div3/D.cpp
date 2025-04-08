//D
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
using u64 = unsigned long long int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

u64 fr(i32 n, i32 x, i32 y) {
    if (n == 1) {
        if (x == 1 && y == 1) return 1;
        if (x == 1 && y == 2) return 4;
        if (x == 2 && y == 1) return 3;
        if (x == 2 && y == 2) return 2;
    }
    i32 h = 1 << (n - 1);
    u64 cnt = 1ull << (2 * (n - 1));
    if (x <= h && y <= h) {
        return fr(n - 1, x, y);
    } else if (x > h && y > h) {
        return fr(n - 1, x - h, y - h) + cnt;
    } else if (x > h && y <= h) {
        return fr(n - 1, x - h, y) + cnt * 2;
    } else {
        return fr(n - 1, x, y - h) + cnt * 3;
    }
}

pii fl(i32 n, u64 d) {
    if (n == 1) {
        if (d == 1) return {1, 1};
        if (d == 4) return {1, 2};
        if (d == 3) return {2, 1};
        if (d == 2) return {2, 2};
    }
    i32 h = 1 << (n - 1);
    u64 cnt = 1ull << (2 * (n - 1));
    if (d <= cnt) {
        return fl(n - 1, d);
    } else if (d <= cnt * 2) {
        auto p = fl(n - 1, d - cnt);
        return {p.first + h, p.second + h};
    } else if (d <= cnt * 3) {
        auto p = fl(n - 1, d - cnt * 2);
        return {p.first + h, p.second};
    } else {
        auto p = fl(n - 1, d - cnt * 3);
        return {p.first, p.second + h};
    }
}

void nhir() {
    i32 n, q;
    std::cin >> n >> q;
    while (q--) {
        std::string op;
        std::cin >> op;
        if (op == "->") {
            i32 x, y;
            std::cin >> x >> y;
            std::cout << fr(n, x, y) << endl;
        } else if (op == "<-") {
            u64 d;
            std::cin >> d;
            auto ans = fl(n, d);
            std::cout << ans.first << " " << ans.second << endl;
        }
    }
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
