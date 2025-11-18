//  B. Drifting Away
//  09:30
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    std::string s;
    std::cin >> s;
    if (s == "*") {
        std::cout << 1 << endl;
        return;
    }
    int l = 0, r = 0;

    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && s[i - 1] == '*' && s[i] == '*') {
            std::cout << -1 << endl;
            return;
        }
        if (i > 0 && s[i - 1] == '>' && s[i] == '*') {
            std::cout << -1 << endl;
            return;
        }
        if (i > 0 && s[i - 1] == '*' && s[i] == '<') {
            std::cout << -1 << endl;
            return;
        }
        if (i > 0 && s[i - 1] == '>' && s[i] == '<') {
            std::cout << -1 << endl;
            return;
        }
        if (i > 0 && s[i - 1] == '<' && s[i] == '<') l++;
        if (i > 0 && s[i - 1] == '>' && s[i] == '>') r++;
        if (s[i] == '*') l++, r++;
    }
    if (l > r) {
        std::cout << l + 1 << enld;
    } else {
        std::cout << r + 1 << endl;
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
