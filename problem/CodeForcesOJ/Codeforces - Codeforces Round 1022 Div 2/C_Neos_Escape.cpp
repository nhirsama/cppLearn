//  C. Neo's Escape
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
using pii = std::pair<i32, i32>;

void nhir() {
    i32 n;
    std::cin >> n;
    std::priority_queue<pii> pq;
    std::vector<bool> st(n + 2);
    std::vector<i32> ai(n + 1);
    for (i32 i = 1; i <= n; i++) {
        std::cin >> ai[i];
        //pq.push({a,i});
    }
    i32 cnt = 0;
    for (i32 i = 1; i <= n; i++) {
        if (ai[i] == ai[i - 1]) continue;
        pq.push({ai[i], ++cnt});
    }
    i32 ans = 0;
    while (!pq.empty()) {
        auto [x,y] = pq.top();
        pq.pop();
        if (st[y - 1] || st[y + 1]) {
            st[y] = true;
        } else st[y] = true, ans++;
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
