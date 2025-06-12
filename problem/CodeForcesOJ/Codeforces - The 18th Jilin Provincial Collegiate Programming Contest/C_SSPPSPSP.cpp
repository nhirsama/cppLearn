//  C. SSPPSPSP
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 998244353;
constexpr char endl = '\n';

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
    i32 n, k;
    std::cin >> n >> k;
    std::vector<i32> v(n);
    i32 pre = 0, pro = 1;
    for (auto &i: v)std::cin >> i, pre += i, pro = pro * i % mod;
    pre %= mod;
    std::string s;
    std::cin >> s;
    i32 ans = 1;
    for (i32 i = k - 1; i >= 0; i--) {
        if (s[i] == 's') {
            if (i == k - 1) ans = pre;
            else {
                ans = ans * n % mod;
            }
//            ans = ans * pre % mod;
//            ans = ans * (i == k - 1 ? pre : n) % mod;
//            ans = (ans * pre + ans * (i != k - 1)) % mod;
        } else {
            if (i == k - 1) ans = pro;
            else {
                ans = power(ans, n, mod);
            }
//            ans = ans * pro % mod;
        }
    }
    std::cout << ans % mod << endl;

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}