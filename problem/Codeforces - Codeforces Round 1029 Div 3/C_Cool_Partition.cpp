//  C. Cool Partition
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i;
    i32 ans = 0;
    i32 cnt = 0;
    std::set<i32> a, b;
    for (i32 i = 0; i < n; i++) {
        if (a.find(v[i]) != a.end() && b.find(v[i]) == b.end()) {
            cnt++;
        }
        b.insert(v[i]);
        if (cnt == a.size()) {
            ans++;
            std::swap(a, b);
            cnt = 0;
            b.clear();
        }
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
