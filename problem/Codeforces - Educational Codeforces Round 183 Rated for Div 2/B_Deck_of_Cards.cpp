//  B. Deck of Cards
//  16:25
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
    std::string s(a, '+');
    std::string ss;
    std::cin >> ss;
    int cnt = 0, itl = 0, itr = a - 1;
    for (auto i: ss) {
        if (i == '2') cnt++;
        if (i == '0') s[itl++] = '-';
        if (i == '1') s[itr--] = '-';
    }
    int t = 0;
    for (int i = 0; i < a; i++) {
        if (t == cnt) break;
        if (s[i] == '+') s[i] = '?', t++;
    }
    t = 0;
    bool f = false;
    for (int i = a - 1; ~i; i--) {
        if (t == cnt) break;
        if (s[i] == '+') s[i] = '?', t++, f = true;
    }
    if (!f && cnt) {
        for (auto &i: s) i = '-';
    }
    std::cout << s << enld;
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
