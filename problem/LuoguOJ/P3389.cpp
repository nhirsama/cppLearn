//P3389 【模板】高斯消元法
#include <bits/stdc++.h>
using i64 = long long int;
using i32 = int;
constexpr double eps = 1e-5;

i64 gauss(std::vector<std::vector<double> > &mat, i32 n) {
    i64 c, r;
    for (c = 0, r = 0; c < n; c++) {
        i64 t = r;
        for (int i = r; i < n; i++) //找到绝对值最大的行
            if (fabs(mat[i][c]) > fabs(mat[t][c]))
                t = i;
        if (fabs(mat[t][c]) < eps) continue;
        for (int j = c; j < n + 1; j++) std::swap(mat[t][j], mat[r][j]); //将绝对值最大的一行换到最顶端
        for (int j = n; j >= c; j--) mat[r][j] /= mat[r][c]; //将当前行首位变成 1
        for (int i = r + 1; i < n; i++) //将下面列消成 0
            if (fabs(mat[i][c]) > eps)
                for (int j = n; j >= c; j--)
                    mat[i][j] -= mat[r][j] * mat[i][c];
        r++;
    }
    if (r < n) {
        for (int i = r; i < n; i++)
            if (fabs(mat[i][n]) > eps)
                return 2;
        return 1;
    }
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            mat[i][n] -= mat[i][j] * mat[j][n];
    return 0;
}

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector mata(n, std::vector<double>(n + 1));
    for (i32 _ = 0; _ < n; _++) {
        for (i32 __ = 0; __ <= n; __++) {
            std::cin >> mata[_][__];
        }
    }
    i64 t = gauss(mata, n);
    if (t == 0) {
        for (i32 i = 0; i < n; i++)
            printf("%.2lf\n", mata[i][n]);
    } else {
        std::cout << "No Solution\n";
    }
}

signed main() {
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }

    while (T--) nhir();
    return 0;
}
