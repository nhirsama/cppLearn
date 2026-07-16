//  Who Watches the Watchpig?
//  22:47
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    if (n / 2 < k) {
        std::cout << -1 << endl;
        return;
    }
    int64 ans = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == 'L') ans++;
        if (s[n - i - 1] == 'R') ans++;
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
