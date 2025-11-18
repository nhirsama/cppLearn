//  Matrix (matrix)
//  下午1:11
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};

void nhir() {
    int n, m;
    std::cin >> n >> m;
    if (std::gcd(m, n) == 1) {
        std::cout << "YES\n";
        std::vector mat(n, std::vector<int>(m, -1));
        mat[0][0] = 1;
        int begin = 0, lei = 0, to = 1;
        int val = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[begin][lei] = ++val;
                lei += to;
            }
            lei -= to;
            if (mat[(begin + val) % n][lei] == -1) {
                begin = (begin + val) % n;
            } else if (mat[(begin - val % n + n) % n][lei] == -1) {
                begin = (begin - val % n + n) % n;
            } else if (i != n - 1) {
                exit(-1);
            }
            to = -to;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << mat[i][j] << ' ';
            }
            std::cout << enld;
        }
    } else {
        std::cout << "NO\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
//        std::cin >> T;
        while (T--) nhir();
    return 0;
}