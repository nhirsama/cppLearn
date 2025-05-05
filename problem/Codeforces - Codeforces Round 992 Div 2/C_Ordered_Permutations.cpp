//  C. Ordered Permutations
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
    if (k > 1ll << std::min(60ll, (n  - 1))) {
        std::cout << -1 << endl;
        return;
    }
    std::queue<i32> q;
    std::stack<i32> s;
    k--;
    for (i32 i = 1; i < n; i++) {
        if (k >> std::min(60ll, (n - i - 1)) & 1) {
            s.push(i);
        } else q.push(i);
    }
    q.push(n);
    while (!q.empty()) {
        std::cout << q.front() << ' ';
        q.pop();
    }
    while (!s.empty()) {
        std::cout << s.top() << ' ';
        s.pop();
    }
    std::cout << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
