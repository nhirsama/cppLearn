//  D - Takahashi's Expectation
//  下午9:33
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    int64 n;
    std::cin >> n;
    std::vector<std::array<int64, 3>> v(n);
    int64 max = 0, tm = 0;
    for (auto &[p, a, b]: v) std::cin >> p >> a >> b, max += std::max(p, b), tm += b;
    std::map<int64, int64> m;
    int q;
    std::cin >> q;
    while (q--) {
        int xi;
        std::cin >> xi;
        if (xi >= max) {
            std::cout << xi - tm << endl;
        } else if (m.find(xi) != m.end()) {
            std::cout << m[xi] << endl;
        } else {
            int t = xi;
            for (auto [p, a, b]: v) {
                if (xi > p) xi = std::max(int64(0), xi - b);
                else xi += a;
            }
            std::cout << xi << endl;
            m[t] = xi;
        }
    }
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