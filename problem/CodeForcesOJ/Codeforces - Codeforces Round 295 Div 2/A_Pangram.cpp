//  A. Pangram
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';

auto get(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    else return c - 'a';
}

void nhir() {
    i32 n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::array<i32, 26> a{};
    for (auto c: s) {
        a[get(c)]++;
    }
    for (i32 i = 0; i < 26; i++) {
        if (a[i] == 0) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}