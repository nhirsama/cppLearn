//  D - Pop and Insert
//  21:59
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    std::string s;
    int n;
    std::cin >> n;
    std::cin >> s;
    int len = 0, maxlen = 0, ans1 = 0, ans0 = 0;
    for (auto i: s) {
        if (i == '0') {
            len++;
            ans0 += 2;
        } else {
            maxlen = std::max(len, maxlen);
            len = 0;
            ans0++;
        }
    }
    maxlen = std::max(len, maxlen);
    len = 0;
    ans0 -= maxlen * 2;
    len = 0, maxlen = 0;
    for (auto i: s) {
        if (i == '1') {
            len++;
            ans1 += 2;
        } else {
            maxlen = std::max(len, maxlen);
            len = 0;
            ans1++;
        }
    }
    maxlen = std::max(len, maxlen);
    len = 0;
    ans1 -= maxlen * 2;
    std::cout << std::min(ans1, ans0) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // if (OJ_NAME != "AtCoder")
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
