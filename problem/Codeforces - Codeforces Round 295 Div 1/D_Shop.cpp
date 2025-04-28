//  D. Shop
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
using pii = std::pair<i32, i32>;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void nhir() {
    struct node {
        i32 op, i;
        long double b;
        i32 num;
    };
    i32 k, n, m;
    std::cin >> k >> n >> m;
    std::vector<i32> ai(k);
    for (auto &i: ai) std::cin >> i;
    std::vector<node> vv1, vv2, vv3;
    for (i32 i = 0; i < n; i++) {
        i32 op, ii;
        double b;
        std::cin >> op >> ii >> b;
        if (op == 1) vv1.push_back({op, ii, b, i + 1});
        if (op == 2) vv2.push_back({op, ii, b, i + 1});
        if (op == 3) vv3.push_back({op, ii, b, i + 1});
    }
    std::ranges::sort(vv1, [](const node &a, const node &b) { return a.b > b.b; });
    std::set<i32> s;
    for (auto &[op,i,b,num]: vv1) {
        if (s.contains(i)) continue;
        if (b <= ai[i - 1]) continue;
        vv2.push_back({op, i, b - ai[i - 1], num});
        s.insert(i);
    }
    std::vector<long double> cnt(1e5 + 1);
    std::ranges::sort(vv2, [](const node &a, const node &b) { return a.b > b.b; });
    for (auto &[op,i,b,num]: vv2) {
        vv3.push_back({op, i, b / (ai[i - 1] + cnt[i - 1]) + 1, num});
        cnt[i - 1] += b;
    }
    std::ranges::sort(vv3, [](const node &a, const node &b) { return a.b > b.b; });
    std::vector<node> ans;
    for (auto [op,i,b,num]: vv3) {
        if (b <= 1) continue;
        // if (op == 1 && !s.contains(i)) {
        //     ans.push_back({op, i, b, num});
        //     s.insert(i);
        // } else if (op != 1) {
        //     ans.push_back({op, i, b, num});
        // }
        ans.push_back({op, i, b, num});
        if (ans.size() >= m) break;
    }
    std::ranges::sort(ans, [](const node &a, const node &b) {
        if (a.op == b.op) return a.num < b.num;
        return a.op < b.op;
    });
    std::cout << std::min((i32) ans.size(), m) << endl;
    for (i32 i = 0; i < std::min((i32) ans.size(), m); i++) {
        std::cout << ans[i].num << ' ';
    }
    std::cout << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
