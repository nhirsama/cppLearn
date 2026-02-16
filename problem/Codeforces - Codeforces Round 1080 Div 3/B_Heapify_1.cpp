//  B. Heapify 1
//  16:51
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p: primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

void nhir() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (auto &i: v) std::cin >> i;
    for (int i = 1; i <= n; i += 2) {
        // if (i == 1 || isprime(i)) {
        std::vector<int> tm;
        for (int j = i; j <= n; j *= 2) {
            tm.push_back(v[j - 1]);
        }
        std::ranges::sort(tm);
        for (int j = i, k = 0; j <= n; j *= 2, k++) {
            v[j - 1] = tm[k];
        }
        // }
    }
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    sieve(2e5 + 10);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}