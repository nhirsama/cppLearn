#define LOCAL
//P3390 【模板】矩阵快速幂
//P2886 [USACO07NOV] Cow Relays G
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
//const int mod = 1e9 + 7;
long long n, t,s,e;

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
                    res.mat[a][b] += this->mat[a][c] * mata.mat[c][b];
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
    cin >> n >>t>>s>>e;
    matrix base(1005, 1005);
    int max1 = 0;
    while (t--) {
        int a,b,w;
        scanf("%d %d %d",&w,&a,&b);
        max1 = max(max(a,b),max1);
        base.mat[b][a] = base.mat[a][b] = w;
    }
    base.i = base.j = max1+1;
    matrix ans(max1+1, max1+1);
    ans = mat_pow(base, n);
    long long min1 = INT_MAX;
    for (int i = 0; i < ans.i; i++) {
        if (ans.mat[s][e]) min1 = min(min1, ans.mat[s][e]);
    }
    cout << min1 << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
