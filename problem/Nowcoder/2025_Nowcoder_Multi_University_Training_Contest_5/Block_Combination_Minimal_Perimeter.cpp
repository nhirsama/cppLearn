//  Block Combination Minimal Perimeter
//  下午12:05
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};
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
    sieve(2e5 + 50);
    int64 n;
    std::cin >> n;
    int64 sum = (n + 1) * n / 2;
    int64 mint = inf_i64;
    for (int64 i = 1; i * i <= sum; i++) {
        if ((sum % i) == 0) {
            int64 t = sum / i;
            if (t >= n || i >= n)
                mint = std::min(sum / i * 2 + i * 2, mint);
        }
    }
    std::cout << mint << endl;
//    auto highBit = [](auto t) {
//        while (t != [](auto l) { return l & -l; }(t)) {
//            t -= [](auto l) { return l & -l; }(t);
//        }
//        return t;
//    };
//    int64 sum = (n + 1) * n / 2;
//    int64 cnt = 1;
//    while ((sum & 1) == 0) {
//        sum >>= 1;
//        cnt <<= 1;
//    }
//    std::cout << sum * 2 + cnt * 2 << endl;
//    std::cout << (n << 2) - [](auto t) {
//        while (t != [](auto l) { return l & -l; }(t)) {
//            t -= [](auto l) { return l & -l; }(t);
//        }
//        return t;
//    }(n) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
//        std::cin >> T;
        while (T--) nhir();
    return 0;
}