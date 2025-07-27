//  A. Recycling Center
//  下午10:36
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int64 n, c;
    std::cin >> n >> c;
    int ans = 0;
    std::vector<int64> v(n);
    std::priority_queue<int64> p;
    for (auto &i: v) {
        std::cin >> i;
        if (i > c) ans++;
        else {
            p.push(i);
        }
    }
    int64 base = 1;
    while (!p.empty()) {
        if (p.top() * base > c) {
            ans++;
        } else {
            base *= 2;
        }
        p.pop();
    }
    std::cout << ans << endl;

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