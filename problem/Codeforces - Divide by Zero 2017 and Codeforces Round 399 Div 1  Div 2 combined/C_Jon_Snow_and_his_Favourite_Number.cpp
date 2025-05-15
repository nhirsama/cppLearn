//  C. Jon Snow and his Favourite Number
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n, k, x;
    std::cin >> n >> k >> x;
    std::vector<i32> v(n), cv(1 << 10), cnt(1 << 10), cntv(1 << 10);
    for (auto &i: v) std::cin >> i;
    for (auto i: v) cnt[i]++;
    for (i32 i = 1; i < 1024; i++) cntv[i] = cnt[i - 1] + cntv[i - 1];
    while (k--) {
        for (i32 i = 0; i < 1024; i++) {
            cv[i ^ x] += (cnt[i] + !(cntv[i] & 1)) / 2;
            cv[i] += (cnt[i] + (cntv[i] & 1)) / 2;
        }
        std::swap(cnt, cv);
        cv = std::vector<i32>(1 << 10);
        cntv = std::vector<i32>(1 << 10);
        for (i32 i = 1; i < 1024; i++) {
            cntv[i] = cnt[i - 1] + cntv[i - 1];
        }
    }
    i32 max = -1, min = -1;
    for (i32 i = 0; i < 1024; i++) {
        if (min == -1 && cnt[i]) min = i;
        if (cnt[i]) max = i;
    }
    std::cout << max << ' ' << min << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
