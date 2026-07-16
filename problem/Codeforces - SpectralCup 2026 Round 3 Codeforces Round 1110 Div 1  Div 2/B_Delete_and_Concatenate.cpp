//  B. Delete and Concatenate
//  22:53
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    i32 n, c;
    std::cin >> n >> c;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    std::ranges::sort(v);
    i32 ans = 0;
    i32 cnt = n / 2;
    // for (auto i: v) {
    //     if (i >= c) cnt++;
    // }
    for (int i = 0; i < n; i++) {
        if (v[i] < c && i < cnt) continue;
        ans += v[i] - c;
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}
