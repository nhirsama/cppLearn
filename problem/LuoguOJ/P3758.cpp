#define LOCAL
//P3390 【模板】矩阵快速幂 //直接复制模板了
//P5789 [TJOI2017] 可乐（数据加强版）
//P3758 [TJOI2017] 可乐
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int mod = 2017;
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
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    long long n,m;
    cin >> n >> m;
    matrix base(n+1, n+1);
    while (m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        base.mat[a][b] = 1;
        base.mat[b][a] = 1;
    }
    long long t;
    cin >> t;

    for (int a = 0; a <= n; a++) {
        base.mat[a][0] = 1;
        base.mat[a][a] = 1;
    }
    matrix ans(n, n);
    ans = mat_pow(base, t);
    long long ans1 = 0;
    for (int a = 0; a <= n; a++) {ans1 += ans.mat[1][a];}
    ans1 = ans1 % mod;
    cout << ans1 << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
