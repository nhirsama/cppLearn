//  B - Get Min
//  下午8:26
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    int q;
    std::cin >> q;
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x;
            std::cin >> x;
            pq.push(x);
        } else {
            std::cout << pq.top() << enld;
            pq.pop();
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