//  C. Valera and Tubes
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'
using pii = std::pair<int, int>;

void nhir() {
    i32 n, m, k;
    std::queue<pii> cell;
    std::cin >> n >> m >> k;
    i32 totx = 1, toty = 1, jmy = 1;
    for (i32 i = 0; i < n * m; i++) {
        cell.push({totx, toty});
        if (toty == m && jmy == 1) jmy = -1, totx++, toty++;
        if (toty == 1 && jmy == -1) jmy = 1, totx++, toty--;
        toty += jmy;
    }
    std::vector ans(k, std::vector<pii>());
    for (i32 i = 0; i < k; i++) {
        if (i != k - 1) {
            ans[i].push_back(cell.front());
            cell.pop();
            ans[i].push_back(cell.front());
            cell.pop();
        } else {
            while (!cell.empty()) {
                ans[i].push_back(cell.front());
                cell.pop();
            }
        }
    }
    for (auto &i: ans) {
        std::cout << i.size() << ' ';
        for (auto &[x, y]: i) {
            std::cout << x << ' ' << y << ' ';
        }
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}