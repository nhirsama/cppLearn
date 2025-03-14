//矩阵加速模板
#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;

//i和j分别表示矩阵的行数和列数，初始化需要定义行数和列数，并重载乘号运算符，每次运算对mod取模。
struct matrix {
    long long rows, cols;
    vector<vector<long long> > mat;

    matrix(long long r, long long c) : rows(r), cols(c), mat(r, vector<long long>(c)) {
    }

    static matrix identity(long long n) {
        matrix res(n, n);
        for (int i = 0; i < n; ++i) res.mat[i][i] = 1;
        return res;
    }

    matrix operator*(const matrix &o) const {
        matrix res(rows, o.cols);
        for (int i = 0; i < rows; ++i)
            for (int k = 0; k < cols; ++k)
                for (int j = 0; j < o.cols; ++j)
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * o.mat[k][j]) % mod;
        return res;
    }
};

//传入方阵a，并对其做p次幂运算，返回一个方阵.
matrix qpow(matrix a, long long p) {
    matrix res = matrix::identity(a.rows);
    for (; p; p >>= 1, a = a * a)
        if (p & 1) res = res * a;
    return res;
}

int main() {
    long long n;
    cin >> n;
    matrix base(2, 2), ans(2, 2);
    base.mat = {
        {1, 12},
        {0, 0}
    };
    ans.mat = {
        {3, 1},
        {-7, 0}
    };
    if (n > 2) {
        ans = base * qpow(ans, n - 2);
        cout << ans.mat[0][0] << endl;
    } else {
        if (n == 1)cout << 12 << endl;
        else cout << 1 << endl;;
    }
    return 0;
}
