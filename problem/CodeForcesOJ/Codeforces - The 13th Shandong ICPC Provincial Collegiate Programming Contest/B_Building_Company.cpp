//  B. Building Company

#include<bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using pii = std::pair<i32, i32>;

void nhir() {
    std::vector<i32> din(1e5 + 1);
    std::map<i32, std::priority_queue<pii, std::vector<pii>, std::greater<> > > m;
    std::map<i32, i32> cnt;
    i32 g;
    std::cin >> g;
    for (i32 i = 0; i < g; i++) {
        i32 ti, ui;
        std::cin >> ti >> ui;
        cnt[ti] = ui;
    }
    i32 n;
    std::cin >> n;
    i32 ans = 0;
    std::map<i32, std::vector<pii> > add;
    for (i32 i = 1; i <= n; i++) {
        std::cin >> din[i];
        for (i32 j = 0; j < din[i]; j++) {
            i32 ai, bi;
            std::cin >> ai >> bi;
            m[ai].push({bi, i});
        }
        i32 ki;
        std::cin >> ki;
        if (din[i] == 0) {
            ans++;
            for (i32 j = 0; j < ki; j++) {
                i32 ai, bi;
                std::cin >> ai >> bi;
                cnt[ai] += bi;
            }
        } else {
            for (i32 j = 0; j < ki; j++) {
                i32 ai, bi;
                std::cin >> ai >> bi;
                add[i].push_back({ai, bi});
            }
        }
    }

    while (ans < n) {
        i32 brcnt = 0;
        for (auto &[x,y]: m) {
            if (y.empty()) {
                brcnt++;
                if (brcnt >= m.size()) {
                    std::cout << ans << endl;
                    return;
                }
                continue;
            }
            bool flag = true;
            while (!y.empty() && cnt[x] >= y.top().first) {
                flag = false;
                if (--din[y.top().second] == 0) {
                    for (auto [ai,bi]: add[y.top().second]) {
                        cnt[ai] += bi;
                    }
                    if (++ans == n) {
                        std::cout << ans << endl;
                        return;
                    }
                }
                y.pop();
            }
            if (flag) {
                brcnt++;
                if (brcnt >= m.size()) {
                    std::cout << ans << endl;
                    return;
                }
            }
        }
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
