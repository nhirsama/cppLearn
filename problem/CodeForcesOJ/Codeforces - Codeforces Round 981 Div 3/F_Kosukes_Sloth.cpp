//  F. Kosuke's Sloth
#include <bits/stdc++.h>

using i64 = long long int;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
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
    i64 n, k;
    std::cin >> n >> k;
    n %= mod;
    if (k == 1) {
        std::cout << n << endl;
    }
    i64 fib[3]{};
    fib[0] = fib[1] = 1;
    i64 cnt = 0;
    for (i64 i = 2; i <= 6 * k; i++) {
        fib[i % 3] = (fib[(i + 1) % 3] + fib[(i + 2) % 3]) % k;
        if (fib[i % 3] == 0) cnt++;
        if (fib[i % 3] == 1 && fib[(i + 2) % 3] == 0) {
            std::cout << 1ll * i * n % mod * power(cnt, mod - 2, mod) % mod << "\n";
            return;
        }
    }
}

signed main() {
    IOS;
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
