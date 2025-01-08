#define LOCAL
//P1962 斐波那契数列
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

struct matrix {
    long long A[3][3];
    matrix() {
        memset(A, 0, sizeof(A));
    }
    matrix operator*(const matrix& b) const {
        matrix temp;
        for (int i = 1; i <=2;i++) {
            for (int j = 1; j <=2;j++) {
                for (int k = 1; k <=2;k++) {
                    temp.A[i][j] = (temp.A[i][j] + A[i][k] * b.A[k][j]) % mod;
                }
            }
        }
        return temp;
    }
} ans, base;
void quick_pow(long long b) {
    while (b) {
        if (b & 1) {
            ans = ans * base;
        }
        base = base * base;
        b >>= 1;
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    base.A[1][1] = base.A[1][2] = base.A[2][1] = 1;
    ans.A[1][1] = ans.A[1][2] = 1;
    long long int n;
    cin >> n;
    if (n <= 2) {
        cout << 1 << endl;
        return 0;
    }
    quick_pow(n-2);
    cout << ans.A[1][1]%mod << endl;


#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}