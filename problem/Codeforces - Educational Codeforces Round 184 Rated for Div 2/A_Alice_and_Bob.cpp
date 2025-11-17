//  A. Alice and Bob
//  11:56
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int n, a;
    std::cin >> n >> a;
    std::vector<int> v(n);
    int b = 0, s = 0;
    for (auto &i: v) {
        std::cin >> i;
        if (i < a) s++;
        else if (i > a) b++;
    }
    if (s >= b) {
        if (a == 0) {
            std::cout << 0 << enld;
            return;
        }
        std::cout << a - 1 << endl;
    } else {
        std::cout << a + 1 << endl;
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
