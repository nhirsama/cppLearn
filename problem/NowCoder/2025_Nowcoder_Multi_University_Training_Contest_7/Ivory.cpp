//  Ivory
//  下午12:04
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 998244353;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};

int64 power(int64 a, int64 b, int64 p) {
    a %= p;
    int64 res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

void nhir() {
    int64 a, b, c, d;
    std::cin >> a >> b >> c >> d;
    auto sgcd = [](auto &&self, int64 a, int64 b, int64 c, int64 d) {
        if (b > d) {
            std::swap(a, c);
            std::swap(b, d);
        }
        int64 gcd = std::gcd(a, c);
        if (gcd == 1)return 1ll;
//        if (a == 1 || c == 1) return 1ll;
        a /= gcd;
        c /= gcd;
        return power(gcd, b, mod) * self(self, a, b, gcd, d - b) % mod;
    };
    std::cout << sgcd(sgcd, a, b, c, d) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}