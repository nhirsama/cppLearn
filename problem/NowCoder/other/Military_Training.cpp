//  Military Training
//  12:17
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};

void nhir() {
    int sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;
    std::cin >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;
    if (sx1 > sx2 || sy1 > sy2) {
        std::swap(sx1, sx2);
        std::swap(sy1, sy2);
    }
    if (tx1 > tx2 || ty1 > ty2) {
        std::swap(tx1, tx2);
        std::swap(ty1, ty2);
    }
    int64 ans = 0;
    if ()
        ans += std::abs(ty1 - sy1) + std::abs(tx1 - sx1);
    if (sx1 - sx2 != tx1 - tx2) ans++;
    std::cout << ans << enld;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}