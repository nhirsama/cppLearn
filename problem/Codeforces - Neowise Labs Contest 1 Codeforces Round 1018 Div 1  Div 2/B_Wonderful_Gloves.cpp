//  B. Wonderful Gloves
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 a, b;
    std::cin >> a >> b;
    std::vector<i32> v(a);
    i32 ans = 0;
    for (i32 i = 0; i < a; i++) {
        std::cin >> v[i];
    }
    for (i32 i = 0; i < a; i++) {
        i32 t;
        std::cin >> t;
        ans += std::max(t, v[i]);
        v[i] = std::min(t, v[i]);
    }
    std::ranges::sort(v, std::greater());
    for (i32 i = 0; i < b - 1; i++) ans += v[i];
    ans++;

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
