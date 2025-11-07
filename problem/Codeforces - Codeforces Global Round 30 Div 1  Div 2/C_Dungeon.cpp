//  C. Dungeon
//  10:34
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::priority_queue<int, std::vector<int>, std::greater<> > pq;
    for (auto &i: a) std::cin >> i, pq.push(i);
    std::vector<std::pair<int, int> > b(m);
    for (auto &i: b | std::views::keys) {
        std::cin >> i;
    }
    for (auto &i: b | std::views::values) {
        std::cin >> i;
    }
    std::ranges::sort(b);
    std::priority_queue<int, std::vector<int>, std::greater<> > pq2;
    int ans = 0;
    for (auto &[x,y]: b) {
        if (y == 0) {
            continue;
        }
        while (!pq.empty()) {
            auto j = pq.top();
            pq.pop();
            if (j >= x) {
                ans++;
                pq.push(std::max(j, y));
                y = -1;
                break;
            } else {
                pq2.push(j);
            }
        }
    }
    while (!pq.empty()) {
        int t = pq.top();
        pq.pop();
        pq2.push(t);
    }
    for (auto [x,y]: b) {
        if (y == -1) continue;
        while (!pq2.empty()) {
            auto j = pq2.top();
            pq2.pop();
            if (j >= x) {
                ans++;
                break;
            }
        }
    }
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
