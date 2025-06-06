//  P10701 [SNCPC2024] 致命公司
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
using ll = i32;

void nhir() {
    i32 n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::array<i32, 3> > v(m);
    std::vector<bool> st(n + 1);
    i32 cnt = 0;
    for (auto &[t,x,y]: v) {
        std::cin >> t >> x >> y;
        if (!st[x]) st[x] = true, cnt++;
    }
    if (cnt == 1) {
        std::cout << -1 << endl;
        return;
    }
    std::ranges::sort(v, [](std::array<i32, 3> &a, std::array<i32, 3> &b) {
        if (a[0] == b[0]) return a[2] < b[2];
        return a[0] > b[0];
    });
    //std::vector<i32> stt(n + 1);
    auto check = [&](i32 ti)-> bool {
        ll ret = ti; //从 ti 开始消耗用于凝视
        std::map<i32, i32> mm;
        for (auto &[t,x,y]: v) {
            if (ti < t) continue; //该子弹还未出现
            ll tmp = (y - 1) / k + 1 + mm[x] + t - 1; //到达时的时间
            if (tmp > ti) continue; //子弹在 ti 时无法达到
            tmp = ti - tmp + 1; //需要凝视的时间
            if (ret - tmp + 1 < t) return 0; //剩余时间无法处理
            ret -= tmp;
            mm[x] += tmp; //进行标记
        }
        // for (int i = 0; i < m; ++i) {
        //     if (ti < v[i][0]) continue; //该子弹还未出现
        //     ll tmp = (v[i][2] - 1) / k + 1 + mm[v[i][1]] + v[i][0] - 1; //到达时的时间
        //     if (tmp > ti) continue; //子弹在 ti 时无法达到
        //     tmp = ti - tmp + 1; //需要凝视的时间
        //     if (ret - tmp + 1 < v[i][0]) return 0; //剩余时间无法处理
        //     ret -= tmp;
        //     mm[v[i][1]] += tmp; //进行标记
        // }
        return 1;
    };
    i32 l = 0, r = 0x3f3f3f3f3f3f3f3f;
    while (l < r) {
        i32 mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    std::cout << l << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
