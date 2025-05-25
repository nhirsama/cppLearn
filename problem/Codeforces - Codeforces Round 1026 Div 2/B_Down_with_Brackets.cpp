//  B. Down with Brackets
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    std::string s;
    std::cin >> s;
    bool f = false;
    std::stack<char> ss;
    for (i32 i = 0; i < s.size(); i++) {
        if (s[i] == '(') ss.push('(');
        if (s[i] == ')') {
            ss.pop();
            if (ss.size() == 0 && i < s.size() - 1) {
                std::cout << "YES\n";
                return;
            }
        }
        // if (f == false && i == ')') f = true;
        // if (f == true && i == '(') {
        //     std::cout << "YES\n";
        //     return;
        // }
    }
    // for (i32 i = 0; i < s.size() - 1; i++) {
    //     if (s[i] == ')' && s[i + 1] == '(') {
    //         std::cout << "YES\n";
    //         return;
    //     }
    // }
    std::cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
