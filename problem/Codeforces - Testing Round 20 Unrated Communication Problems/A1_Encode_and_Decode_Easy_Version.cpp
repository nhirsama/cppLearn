//  A1. Encode and Decode (Easy Version)
//  09:33
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    std::string fs;
    std::cin >> fs;
    if (fs == "first") {
        int n;
        std::cin >> n;
        std::vector<int> v(n);
        for (auto &i: v) std::cin >> i;
        for (auto i: v) {
            std::cout << (char) (i + 'a' - 1);
        }
        std::cout << endl;
    } else {
        std::string s;
        std::cin >> s;
        std::cout << s.size() << endl;
        for (auto c: s) {
            std::cout << (int) (c - 'a' + 1) << ' ';
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        // std::cin >> T;
        while (T--) nhir();
    return 0;
}
