//  D1. Removal of a Sequence (Easy Version)
//  11:26
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int64 x, y, k;
    std::cin >> x >> y >> k;
    if (k <= y - 1) {
        std::cout << k << endl;
        return;
    }
    int64 l = 1, r = 1e12 + 0x3f3f3f;
    while (l < r) {
        auto check = [&](int64 mid) {
            int64 cnt = mid;
            for (int64 i = y; i < y + std::min(y, x); i++) {
                cnt -= mid / i;
            }
            if (cnt >= k) return true;
            else return false;
        };
        int64 mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (l > 1e12) {
        std::cout << -1 << endl;
        return;
    }
    std::cout << l << enld;
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
