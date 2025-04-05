//B
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

int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

void nhir() {
    i32 t;
    std::cin >> t;
    std::vector<pii> query(t);
    for (i32 i = 0; i < t; i++) {
        std::cin >> query[i].first;
    }
    for (i32 i = 0; i < t; i++) {
        std::cin >> query[i].second;
    }
    for (auto &i: query) {
        std::cout << power(2, i.second, mod) << endl;
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
