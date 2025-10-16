//  C1. The Cunning Seller (easy version)
//  01:24
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

int power(long long _a, long long b, int p) {
    int res = 1;
    int a = _a % p;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

long long power(long long a, long long b) {
    long long res = 1;
    for (; b; b /= 2, a = a * a) {
        if (b % 2) {
            res = res * a;
        }
    }
    return res;
}

void nhir() {
    int64 n;
    std::cin >> n;
    int64 ans = 0, cnt = 0;
    while (n) {
        int t = n % 3;
        n /= 3;
        ans += t * (power(3, cnt + 1) + cnt * power(3, cnt - 1));
        cnt++;
    }
    std::cout << ans << enld;
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
