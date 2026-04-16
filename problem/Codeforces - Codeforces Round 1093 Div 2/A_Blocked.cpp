//  A. Blocked
//  08:26
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
    for (auto &i: v) {
        std::cin >> i;
    }
    std::ranges::sort(v);
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == v[i + 1]) {
            std::cout << -1 << endl;
            return;
        }
    }
    for (int i = n - 1; ~i; i--) {
        std::cout << v[i] << ' ';
    }
    std::cout << endl;
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
