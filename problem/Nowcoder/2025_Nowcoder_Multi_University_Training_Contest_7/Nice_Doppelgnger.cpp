//  Nice Doppelgnger
//  下午12:35
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

std::vector<int> ans;

void nhir() {
    int64 n;
    std::cin >> n;
    for (int i = 0; i < n / 2; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << endl;
//    for (int64 i = 2; i <= n; i++) {
//        int64 t = i;
//        std::map<int, int> m;
//        for (auto p: primes) {
//            if (t == 1) break;
//            while (t % p == 0) {
//                m[p]++;
//                t /= p;
//            }
//        }
////        if (m.size() % 2 == 0) continue;
//        bool ok = false;
//        int odd = 0, even = 0;
//        for (auto [_, nu]: m) {
//            if (nu % 2 == 1) {
//                even++;
//            } else odd++;
//        }
//        if (even % 2 == 0)continue;
////        if ()
//        ans.push_back(i);
//    }
//    for (int i = 0; i < n / 2; i++) {
//        std::cout << ans[i] << ' ';
//    }
//    std::cout << endl;



}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    sieve(1e6 + 10);
    for (int i = 2; i <= 1e6 + 10; i++) {
        //    for (int64 i = 2; i <= n; i++) {
        int64 t = i;
        std::map<int, int> m;
//        for (auto p: primes) {
        while (t > 1) {
            m[minp[t]]++;
            t /= minp[t];
        }
//            if (t == 1) break;
//            while (t % p == 0) {
//                m[p]++;
//                t /= p;
//            }
//        if (m.size() % 2 == 0) continue;
        bool ok = false;
        int odd = 0, even = 0;
        for (auto [_, nu]: m) {
            if (nu % 2 == 1) {
                even++;
            } else odd++;
        }
        if (even % 2 == 0)continue;
//        if ()
        ans.push_back(i);
    }
//        auto check = [&](int64 t) {
//            for (auto j: ans) {
//                for (auto k: ans) {
//                    int64 sq = std::sqrt(t * j * k);
//                    if (t * j * k == sq * sq) {
//                        return false;
//                    }
//                }
//            }
//            return true;
//        };
//        if (check(i)) ans.push_back(i);
//        if (ans.size() == (1e6+10) / 2) {
//            for (auto j: ans) {
//                std::cout << j << ' ';
//            }
//            std::cout << endl;
//            return;
//        }

    if (OJ_NAME != "AtCoder")
        std::cin >>
                 T;
    while (T--)

        nhir();

    return 0;
}