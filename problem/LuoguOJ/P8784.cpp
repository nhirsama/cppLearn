//P8784 [蓝桥杯 2022 省 B] 积木画
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

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
    cin>>n;
    matrix init(4,4),base(4,4);
    init.mat[0] = {5,2,1,1};
    base.mat = {{1,1,0,0},{2,0,1,0},{1,0,0,1},{1,0,0,0}};
    if (n<=3) {
        cout<<init.mat[0][3-n];
        return 0;
    }
    matrix ans = init*qpow(base,n-3);
    cout<<ans.mat[0][0]<<endl;
    return 0;
}
