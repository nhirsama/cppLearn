//  A - AtCoder Language
//  下午8:23
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
    std::cin >> s;
    if (s == "red") {
        std::cout << "SSS" << endl;
    } else if (s == "blue") {
        std::cout << "FFF" << enld;
    } else if (s == "green") {
        std::cout << "MMM\n";
    } else {
        std::cout << "Unknown\n";
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