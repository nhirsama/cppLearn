//  C. Need More Arrays
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    std::stack<i32> s;
    for (auto i: v) {
        if (s.empty())s.push(i);
        else {
            if (i - s.top() >= 2) s.push(i);
        }
    }
    std::cout << s.size() << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
