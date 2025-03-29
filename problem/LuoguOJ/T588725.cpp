//T588725 化食欲为动力
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i64 n, m, k;
    std::cin >> n >> m >> k;
    std::vector<i64> ai(n), bi(m), ci(k);
    for (i64 &i: ai) std::cin >> i;
    for (i64 &i: bi) std::cin >> i;
    for (i64 &i: ci) std::cin >> i;
    i64 max = 0;
    for (i64 i: ai) {
        for (i64 j: bi) {
            for (i64 k1: ci) {
                max = std::max(i * j % k1, max);
            }
        }
    }
    std::cout << max << endl;
}

signed main() {
    IOS;
    i32 T = 1;

    while (T--) nhir();
    return 0;
}
