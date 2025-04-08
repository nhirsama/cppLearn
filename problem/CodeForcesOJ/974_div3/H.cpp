//H
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
using u64 = unsigned long long;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i64 n, q;
    std::cin >> n >> q;
    std::vector<u64> v(n);
    for (auto &i: v) std::cin >> i;
    std::random_device rd;
    std::mt19937_64 random(std::time(nullptr));
    std::map<u64, u64> m;
    std::set<u64> s;
    for (auto &i: v) {
        u64 t = random();
        if (!m.count(i)) {
            while (s.count(t)) t = random();
            s.insert(t);
            m[i] = t;
        } else t = m[i];
        i = t;
    }
    std::vector<u64> xorpre(n + 1);
    for (i32 i = 0; i < n; i++) {
        xorpre[i + 1] = xorpre[i] ^ v[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << ((xorpre[r] ^ xorpre[l - 1]) ? "NO\n" : "YES\n");
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
