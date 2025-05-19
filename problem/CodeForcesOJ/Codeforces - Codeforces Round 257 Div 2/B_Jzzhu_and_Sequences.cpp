//  B. Jzzhu and Sequences
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
using namespace std;

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
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * o.mat[k][j] + mod) % mod;
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


void nhir() {
    i32 x, y;
    std::cin >> x >> y;
    i32 n;
    std::cin >> n;
    matrix base(2, 2);
    base.mat = {{1ll, 1ll}, {-1ll, 0ll}};
    matrix ans(2, 2);
    ans.mat = {{y, x}, {}};
    if (n == 1) {
        std::cout << (x + mod) % mod << endl;
    } else if (n == 2) {
        std::cout << (y + mod) % mod << endl;
    } else {
        ans = ans * qpow(base, n - 1);
        std::cout << (ans.mat[0][1] + mod) % mod << endl;
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
