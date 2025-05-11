//  E - Bowls and Beans
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> c(n), a(n);
    for (i32 i = 1; i <= n; i++) std::cin >> c[i];
    for (i32 i = 1; i <= n; i++) std::cin >> a[i];
    std::vector<i32> dp(n+1);
    // for (auto &i:c) std::cin>>i;
    // for (auto &i:a) std::cin>>i;
    // std::vector g(n+1,std::vector<i32>());
    // for (i32 i = 0;i<n;i++) {
    //
    // }
    // vector<int> dis(n + 1, 1E18);
    // auto djikstra = [&](int s = 0) -> void {
    //     using PII = pair<int, int>;
    //     priority_queue<PII, vector<PII>, greater<PII>> q;
    //     q.emplace(0, s);
    //     dis[s] = 0;
    //     vector<int> vis(n + 1);
    //     while (!q.empty()) {
    //         int x = q.top().second;
    //         q.pop();
    //         if (vis[x]) continue;
    //         vis[x] = 1;
    //         for (auto [y, w] : ver[x]) {
    //             if (dis[y] > dis[x] + w) {
    //                 dis[y] = dis[x] + w;
    //                 q.emplace(dis[y], y);
    //             }
    //         }
    //     }
    // };
    // i32 ans = 0;
    // for (i32 i = n - 1; i; i--) {
    //     if (a[i] > 0) {
    //         ans++;
    //         a[std::max(0ll,i - c[i])] += a[i];
    //     }
    // }

    std::cout << ans << "\n";
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
