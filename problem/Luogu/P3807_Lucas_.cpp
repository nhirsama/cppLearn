//  P3807 【模板】卢卡斯定理/Lucas 定理
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

int C(const std::vector<int> &jc, int n, int k, int p) {
    if (n < 0 || k < 0 || n < k) return 0;
    return 1ll * jc[n] * power(jc[k], p - 2, p) % p * power(jc[n - k], p - 2, p) % p;
}

int lucas(const std::vector<int> &jc, int n, int k, int p) {
    if (k == 0) return 1;
    return 1ll * (C(jc, n % p, k % p, p) * lucas(jc, n / p, k / p, p)) % p;
}

void nhir() {
    i32 n, m, P;
    std::cin >> n >> m >> P;
    std::vector<int> jc(P);
    jc[0] = 1;
    for (int i = 1; i < P; i++) {
        jc[i] = 1ll * jc[i - 1] * i % P;
    }
    std::cout << lucas(jc, n + m, n, P) << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
