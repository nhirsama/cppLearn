//  P6824 「EZEC-4」可乐
//  17:48
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Luogu"};

void nhir() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> diff((1 << 20));
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        int tot = 0;
        for (int j = 20; ~j; j--) {
            if ((k >> j) & 1) {
                if ((a >> j) & 1) {
                    diff[tot + (1 << j)]++;
                    diff[tot + (1 << (j + 1))]--;
                } else {
                    diff[tot]++;
                    diff[tot + (1 << j)]--;
                    tot += 1 << j;
                }
            } else {
                if (a >> j & 1) {
                    tot += (1 << j);
                }
            }
        }
        diff[tot]++, diff[tot + 1]--;
    }
    int ans = 0;
    for (int i = 0; i < (1 << 20) - 1; i++) {
        diff[i + 1] += diff[i];
        ans = std::max(diff[i], ans);
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        // std::cin >> T;
        while (T--) nhir();
    return 0;
}
