//  D. The 67th OEIS Problem
//  11:10
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

void nhir() {
    int64 n;
    std::cin >> n;
    std::vector<int64> ans(n);
    std::set<int64> m;

    for (int i = 0; i < n; i++) {
        ans[i] = 1ll * primes[i] * primes[i + 1];
        if (i) {
            int64 gcd = std::gcd(ans[i - 1], ans[i]);
            if (m.find(gcd) == m.end()) {
                m.insert(gcd);
            } else {
                exit(1);
            }
        }
    }
    for (auto i: ans) {
        std::cout << i << ' ';
    }
    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    sieve(1e6);
    // std::cout << primes.size() << endl;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}
