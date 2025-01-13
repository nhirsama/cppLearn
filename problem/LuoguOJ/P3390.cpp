#define LOCAL
//P3390 【模板】矩阵快速幂
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long n, k;

struct matrix {
    long long i, j;
    vector<vector<long long> > mat;

    matrix(long long a, long long b) {
        this->i = a;
        this->j = b;
        this->mat = vector<vector<long long> >(a, vector<long long>(b, 0));
    }

    matrix operator*(const matrix &mata) const {
        matrix res(i, mata.j);
        for (int a = 0; a < i; a++) {
            for (int b = 0; b < mata.j; b++) {
                for (int c = 0; c < j; c++) {
                    res.mat[a][b] += this->mat[a][c] * mata.mat[c][b] % mod;
                    res.mat[a][b] %= mod;
                }
            }
        }
        return res;
    }
};

matrix mat_pow(matrix a, long long b) {
    matrix res(a.i, a.i);
    for (int i = 0; i < a.i; i++) {
        res.mat[i][i] = 1;
    }
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        b = b >> 1;
        a = a * a;
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("inAndoutFile/P3390_1.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> k;
    matrix base(n, n);
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            scanf("%lld", &base.mat[a][b]);
        }
    }
    matrix ans(n, n);
    ans = mat_pow(base, k);

    for (int a = 0; a < ans.i; a++) {
        for (int b = 0; b < ans.j; b++) {
            printf("%lld ", ans.mat[a][b]);
        }
        printf("\n");
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
