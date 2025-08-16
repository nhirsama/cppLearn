//  D - Substr Swap
//  下午8:54
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<int> cf(n + 1);
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        cf[l - 1]++;
        cf[r]--;
    }
    for (int i = 0; i < n; i++) {
        cf[i + 1] += cf[i];
    }
    for (int i = 0; i < n; i++) {
        if (cf[i] & 1) {
            std::swap(s[i], t[i]);
        }
    }
    std::cout << s << endl;
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