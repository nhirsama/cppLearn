//  A2. Encode and Decode (Hard Version)
//  09:44
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    auto to8 = [](int n) {
        std::stack<char> st;
        for (int i = 0; i < 8; i++) {
            st.push(n % 26);
            n /= 26;
        }
        std::string s;
        while (!st.empty()) {
            s.push_back(st.top() + 'a');
            st.pop();
        }
        return s;
    };
    std::string fs;
    std::cin >> fs;
    if (fs == "first") {
        int n;
        std::cin >> n;
        std::vector<int> v(n);
        std::cout << to8(n);
        for (auto &i: v) std::cin >> i;
        for (auto i: v) {
            std::cout << to8(i);
        }
        std::cout << endl;
    } else {
        auto nto = [&](std::string s) {
            int res = 0;
            for (auto i: s) {
                res = res * 26 + i - 'a';
            }
            return res;
        };
        std::string s;
        std::cin >> s;
        int n = nto(s.substr(0, 8));
        std::cout << n << endl;
        for (int i = 0; i < n; i++) {
            std::cout << nto(s.substr(i * 8 + 8, 8)) << ' ';
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
