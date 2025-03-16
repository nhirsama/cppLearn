//P1306 斐波那契公约数
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e8;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

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

signed main() {
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    IOS;
    matrix ans(2, 1), base(2, 2);
    ans.mat = {{1, 1}};
    base.mat = {{1, 1}, {1, 0}};
    i64 n, m;
    cin >> n >> m;
    i64 p = gcd(m, n);
    if (p < 2) {
        cout << p << endl;
    } else {
        ans = ans * qpow(base, p - 1);
        cout << ans.mat[0][0] << endl;
    }
    return 0;
}
