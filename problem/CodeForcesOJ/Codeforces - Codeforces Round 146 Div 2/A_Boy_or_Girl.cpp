//  A. Boy or Girl
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    std::string s;
    std::cin>>s;
    std::set<char> se;
    for (auto i: s) {
        se.insert(i);
    }
    std::cout << ((se.size() & 1) ? "IGNORE HIM!" : "CHAT WITH HER!");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}