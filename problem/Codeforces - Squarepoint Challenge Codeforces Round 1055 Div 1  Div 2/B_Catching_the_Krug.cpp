//  B. Catching the Krug
//  13:18
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    i32 n, a, b, c, d;
    std::cin >> n >> a >> b >> c >> d;
    i32 max = 0;
    if (a > c) max = std::max(max, n - c);
    if (a < c) max = std::max(max, c);
    if (b > d) max = std::max(max, n - d);
    if (b < d) max = std::max(max, d);
    std::cout << max << endl;
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
