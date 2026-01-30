//  B. Prefix Max
//  17:55
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (auto &i: v) std::cin >> i;
    std::ranges::sort(v);
    int ans = 1, t = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1] + 1) t++;
        else if (v[i] == v[i - 1]) {
        } else {
            ans = std::max(ans, t);
            t = 1;
        }
    }
    ans = std::max(ans, t);
    std::cout << ans << enld;
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