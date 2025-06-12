//  G. BF Calculator
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    std::string s;
    std::cin >> s;
    s += '+';
    i32 ans = 0, sing = 1, cur = 0;
    for (auto c: s) {
        if (c == '+' || c == '-') {
            ans += sing * cur;
            cur = 0;
        }
        if (c == '+') sing = 1;
        else if (c == '-') sing = -1;
        else cur = cur * 10 + c - '0';
    }
    std::stack<char> st;
    if (!ans) st.push('0');
    while (ans) {
        st.push(ans % 10 + '0');
        ans /= 10;
    }
    while (!st.empty()) {
        for (i32 i = 0; i < st.top(); i++) {
            std::cout << '+';
        }
        std::cout << '.' << '>';
        st.pop();
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) nhir();
    return 0;
}
