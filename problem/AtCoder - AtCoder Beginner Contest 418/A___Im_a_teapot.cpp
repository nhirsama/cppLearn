//  A - I'm a teapot
//  14:10
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    int n;
    std::cin >> n;
    if (n < 3) {
        std::cout << "No\n";
    } else {
        std::string s;
        std::cin >> s;
        if (s.substr(n - 3) != "tea") {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
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
