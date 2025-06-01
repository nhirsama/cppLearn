//  A. The New Year: Meeting Friends
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    std::vector<i32> v(3);
    for (auto &i: v) std::cin >> i;
    std::ranges::sort(v);
    std::cout << v[2] - v[0] << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}