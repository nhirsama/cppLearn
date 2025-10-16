#include  <bits/stdc++.h>
#define int long long
using i64 = long long;
constexpr int mod = 998244353;
constexpr int N = 2e5 + 5;

int fac[N], ifac[N];

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = (1ll * ans * a) % mod;
        a = (1ll * a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int C(int n, int k) {
    if (n < k) return 0;
    i64 ans = fac[n];
    ans = ans * ifac[k] % mod;
    ans = ans * ifac[n - k] % mod;
    return ans;
}

void solve() {
    i64 n;
    std::cin >> n;
    std::vector<i64> v(n);
    for (auto &i: v) std::cin >> i;
    std::sort(v.begin(), v.end());
    i64 ans = 0;
    // for (int i = 1; i <= n; i++) {
    //     ans = (ans + v[i - 1] * (power(2, n - i) + power(2, i - 1)) % mod) % mod;
    // }
    for (int i = 1; i <= n; i++) {
        int pow = power(2, n - i);
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum = (sum + 1ll * C(i - 1, j) * power(2, std::max(0ll, j - 1))) % mod;
        }
        // int anss = pow * sum * v[i - 1] % mod;
        // std::cout << anss << ' ';
        ans = (ans + 1ll * pow * sum % mod * v[i - 1]) % mod;
    }
    std::cout << ans << '\n';
    // std::vector<i64> dp(n);
    // dp[0] = v[0];
    // for (int i = 1; i < n; i++) {
    //     dp[i] = (dp[i-1] + v[i]+dp[i-1]) % mod;
    // }
    // i64 sum = 0;
    // for (int i = 0; i < n; i++) {
    //     sum = (dp[i] + sum) % mod;
    // }
    // for (int i = 0; i < n; i++) {
    //     dp[i] = v[i] * (i + 1) * i % mod;
    // }
    // i64 ans = 0;
    // for (int i = 0; i < n; i++) {
    //     ans = (ans + dp[i]) % mod;
    // }
    // i64 ans = 0, sum = 0;
    // for (i64 i = n - 1; ~i; i--) {
    //     ans = (ans + v[i] + sum) % mod;
    //     sum = (v[i] + sum + sum) % mod;
    // }
    // std::cout << sum << '\n';
}

signed main() {
    // std::cout << power(2, 10);
    fac[0] = 1;

    for (int i = 1; i < N; i++) {
        fac[i] = (1ll * fac[i - 1] * i) % mod;
    }
    ifac[N - 1] = power(fac[N - 1], mod - 2);
    for (int i = N - 1; ~i; i--) {
        ifac[i - 1] = 1ll * ifac[i] * i % mod;
    }
    // std::cout << C(0, 0) << '\n';
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}

/*
 1
 0
 0 0 0 0 0 0 0

1
30
10 10 2 10 2 2 3
 */
