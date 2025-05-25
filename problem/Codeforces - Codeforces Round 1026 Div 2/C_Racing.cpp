//  C. Racing
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'
using pii = std::pair<i32, i32>;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> d(n);
    for (auto &i: d) std::cin >> i;
    std::vector<pii> h(n);
    std::vector<pii> lh;
    for (auto &[x, y]: h) std::cin >> x >> y;
    i32 low = 0, high = 0;
    for (i32 i = 0; i < n; i++) {
        auto [x, y] = h[i];
//        if (i) {
//            if (x > maxh[i - 1].first) {
//                maxh[i] = {x, std::max(0ll, d[i])};
//            } else {
//                maxh[i].second = maxh[i - 1].second + std::max(d[i], 0ll);
//            }
//        } else maxh[i] = {x, std::max(0ll, d[i])};
//        maxh[i] = std::max((i ? maxh[i - 1] : 0), x);
        if (d[i] == -1) high++;
        else high += d[i], low += d[i];
        high = std::min(y, high);
        low = std::max(x, low);
        lh.emplace_back(low, high);
        //std::cout << low << ' ' << high << endl;
        if (high < low) {
            std::cout << -1 << endl;
            return;
        }
    }
    std::vector<i32> p;
    i32 now = 0;
    for (i32 i = 0; i < n; i++) {
        if (d[i] == -1) {
            p.push_back(i);
        } else now += d[i];
        //std::cout << lh[i].first << ' ' << lh[i].second << '\n';
        while (now < lh[i].first) {
            d[p.back()] = 1;
            now++;
            p.pop_back();
        }
    }
    while (!p.empty()) {
        d[p.back()] = 0;
        p.pop_back();
    }
//    for (i32 i = n - 1; ~i; i--) {
//        if (d[i] == 1)low--;
//        else if (d[i] == -1) {
//            if (low + maxh[i].second >= maxh[i].first)d[i] = 1, low--;
//            else d[i] = 0;
//        }
//    }
    //for (auto i: maxh) std::cout << i << ' ';
    for (auto i: d) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}