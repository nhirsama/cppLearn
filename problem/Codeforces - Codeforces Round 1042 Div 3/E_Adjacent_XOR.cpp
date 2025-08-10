//  E. Adjacent XOR
//  23:27
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int n;
    std::cin >> n;
    std::vector a(n, std::array<int, 2>());
    std::vector<int> b(n);
    for (auto &i: a) std::cin >> i[0], i[1] = i[0];
    for (auto &i: b) std::cin >> i;
    if (a.back()[0] != b.back()) {
        std::cout << "NO" << enld;
        return;
    }
    for (int i = n - 2; ~i; i--) {
        if (a[i][1] != b[i]) {
            if ((a[i][0] ^ a[i + 1][0]) == b[i]) {
                a[i][1] ^= a[i + 1][0];
            } else if ((a[i][0] ^ a[i + 1][1]) == b[i]) {
                a[i][1] ^= a[i + 1][1];
            } else {
                std::cout << "NO\n";
                return;
            }
        }
        // if (s.find(b[i]) == s.end()) {

        // }
        // if (a[i] != b[i]) {
        //     if ((a[i] ^ a[i + 1]) == b[i]) {
        //         a[i] ^= a[i + 1];
        //     } else {
        //         std::cout << "NO\n";
        //         return;
        //     }
        // }
    }
    std::cout << "YES\n";
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
