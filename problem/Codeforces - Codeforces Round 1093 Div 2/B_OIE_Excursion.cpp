//  B. OIE Excursion
//  08:35
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int n, p;
    std::cin >> n >> p;
    std::vector<int> v(n);
    for (auto &i: v) std::cin >> i;
    int cnt = 0, fr = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == fr) cnt++;
        else {
            fr = v[i];
            if (cnt >= p) {
                std::cout << "NO\n";
                return;
            }
            cnt = 1;
        }
    }
    if (cnt >= p) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
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
