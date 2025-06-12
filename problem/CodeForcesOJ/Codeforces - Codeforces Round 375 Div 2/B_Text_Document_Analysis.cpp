//  B. Text Document Analysis
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::stack<char> st;
    i32 cntout = 0, cntin = 0, ansout = 0, ansin = 0;
    for (auto i: s) {
        if (i == '(') {
            st.push('(');
            ansout = std::max(cntout, ansout);
            cntout = 0;
        } else if (i == ')') {
            st.pop();
            ansin += (cntin != 0);
            cntin = 0;
        } else if (i == '_') {
            if (st.empty()) {
                ansout = std::max(cntout, ansout);
                cntout = 0;
            } else {
                ansin += (cntin != 0);
                cntin = 0;
            }
        } else {
            if (st.empty()) {
                cntout++;
            } else cntin++;
        }
    }
    ansout = std::max(cntout, ansout);
    std::cout << ansout << ' ' << ansin << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}
