//  Ad-hoc Newbie
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    int64 n;
    std::cin >> n;
    std::vector mat(n, std::vector<int>(n));
    std::queue<int> q;
    std::vector<int> f(n);
    for (auto &i: f) std::cin >> i;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < f[i]; k++) {
            q.push(k);
        }
        for (int j = 0; j <= i; j++) {
            if (q.empty() || (q.size() == 1 && q.front() == f[j])) mat[i][j] = mat[j][i] = 0;
            else {
                while (q.front() == f[j]) {
                    q.push(q.front());
                    q.pop();
                }
                mat[j][i] = mat[i][j] = q.front();
                q.pop();
            }
        }
    }
//    for (int i = 0; i < n; i++) {
//        int pos = n - 1;
//        int f;
//        std::cin >> f;
//        for (int j = i; j < n + i; j++) {
//            if (i == j) {
//                if (i != n - 1)
//                    mat[i][j % n] = f - 1;
//                else mat[0][i] = f - 1;
//                mat[0][i] = f - 1;
////                std::cout << f - 1 << ' ';
//            } else {
//                mat[i][j % n] = (pos + n) % n;
////                std::cout << (pos + n) % n << ' ';
//            }
//            pos--;
//        }
//    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << enld;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}