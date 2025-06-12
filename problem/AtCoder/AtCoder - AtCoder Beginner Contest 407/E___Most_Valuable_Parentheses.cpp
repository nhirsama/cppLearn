//  E - Most Valuable Parentheses
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(2 * n);
    for (auto &i: v)std::cin >> i;
    std::priority_queue<i32> p;
    i32 ans = 0, cnt = 0;
    for (i32 i = 0; i < 2 * n; i++) {
        p.push(v[i]);
        if (cnt < (i + 2) / 2) {
            ans += p.top();
            p.pop();
            cnt++;
        }
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}