//  A. Greedy Monocarp
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::priority_queue<i32> pq;
    for (i32 i = 1; i <= n; i++) {
        i32 t;
        std::cin >> t;
        pq.push(t);
    }
    i32 sum = 0;
    while (!pq.empty() && sum < k) {
        auto t = pq.top();
        pq.pop();
        if (t + sum > k) {
            break;
        }
        sum += t;
    }
    std::cout << k - sum << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
