//  He can't hack more, He can only send announcements
//  16:22
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};

void nhir() {
    std::string s;
    std::cin >> s;
    int a = -1, b = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '9') a = i + 1;
        if (s[i] == '1') b = i + 1;
    }
    if (a == -1 || b == -1) {
        std::cout << -1 << endl;
    } else {
        std::cout << a << ' ' << b;
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