//  A. Another Sorting Problem
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector<std::pair<std::string, int> > s(n);
    i32 tot = 1;
    for (auto &i: s)std::cin >> i.first, i.second = tot++;
    std::ranges::sort(s, [&m](auto a, auto b) {
        for (i32 i = 0; i < m; i++) {
            if (a.first[i] != b.first[i]) {
                if (i & 1) {
                    return a.first[i] > b.first[i];
                } else return a.first[i] < b.first[i];
            }
        }
        return false;
    });
    for (auto &[x, y]: s) {
        std::cout << y << ' ';
    }
    std::cout << endl;

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}