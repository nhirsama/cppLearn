//  C. Leftmost Below
//  下午11:06
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
    std::vector<int64> v(n);
    for (auto &i: v)std::cin >> i;
    std::vector<int64> pre_min(n + 1);
    pre_min[0] = inf_i64;
    for (int i = 0; i < n; i++) {
        pre_min[i + 1] = std::min(pre_min[i], v[i]);
    }
    for (int i = 1; i < n; i++) {
        if (v[i] >= pre_min[i] * 2) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
    return;
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