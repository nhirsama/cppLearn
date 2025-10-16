//  C - Flush
//  18:30
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> v(n);
    int max = 0, sum = 0;
    for (auto &i: v)std::cin >> i, max = std::max(max, i);
    std::vector<int64> pre(1e6 + 10);
    std::vector<int> big(1e6 + 10);
    for (int i = 0; i < n; i++) {
        big[v[i]]++;
    }
    for (int i = 0; i < 1e6; i++) {
        big[i + 1] += big[i];
    }
    for (int i = 0; i < n; i++) {
        // pre[i + 1] = pre[i] + v[i];
        pre[0]++;
        pre[v[i]]--;
    }
    for (int i = 0; i <= 1e6; i++) {
        pre[i + 1] += pre[i];
        // std::cout << pre[i] << ' ';
    }
    for (int i = 0; i <= 1e6; i++) {
        pre[i + 1] += pre[i];
        // std::cout << pre[i] << ' ';
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t > max) {
            std::cout << -1 << enld;
        } else {
            std::cout << pre[t - 1] + big[t - 1] - n + 1 << enld;
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
