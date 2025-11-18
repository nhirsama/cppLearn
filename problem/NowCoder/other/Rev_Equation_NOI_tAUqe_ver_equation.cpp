//  Rev Equation (NOI-tAUqe ver.) (equation)
//  下午12:23
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};

void nhir() {
//    for (int i = 0; i <= 9; i++) {
//        for (char j: {'+', '-', '*'}) {
//            for (int k = 0; k <= 9; k++) {
//                std::cout << i << j << k << "=\n";
//            }
//        }
//    }
    std::string s;
    std::cin >> s;
    if (s[0] == s[2]) {
        std::cout << "No\n";
    } else if (s[1] == '-') {
        if (s[0] == '0' && s[2]) {
            std::cout << "Yes\n";
        } else std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
    }
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