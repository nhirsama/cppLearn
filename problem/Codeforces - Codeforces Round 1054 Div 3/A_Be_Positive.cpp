//  A. Be Positive
//  19:18
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int64 n;
    std::cin >> n;
    std::vector<int> v(n);
    for (auto &i: v)std::cin >> i;
    int sum = 0, cnt = 0;
    for (auto i: v) {
        if (i == 0) sum++;
        else if (i == -1) cnt++;
    }
    if (cnt & 1) sum += 2;
    std::cout << sum << endl;
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
