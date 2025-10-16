//  B. Hamiiid, Haaamid... Hamid?
//  01:50
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int a, b;
    std::cin >> a >> b;
    std::string s;
    std::cin >> s;
    if (b == 1 || b == s.size()) {
        std::cout << 1 << endl;
        return;
    }
    int c = 0x3f3f3f3f, d = 0x3f3f3f3f;
    for (int i = b - 1; i < s.size(); i++) {
        if (s[i] == '.') c = std::min(c, (int) s.size() - i);
        else break;
    }
    for (int i = b - 1; ~i; i--) {
        if (s[i] == '.') d = std::min(d, i + 1);
        else break;
    }
    // if (c == 1 && d == 1) {
    //     std::cout << 1 << enld;
    //     return;
    // }

    // if (s[b - 1] == '#' || s[b + 1] == '#') {
    std::cout << std::max(std::min(d, int(s.size()) - b + 1), std::min(c, b)) << enld;
    return;
    // }
    // std::cout << std::max(c, d) << endl;
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
