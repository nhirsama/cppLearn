//模板
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

long long qpow(long long a, long long b,int MOD) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void Func() {
    long long a, b, c, n;
    cin >> a >> b >> c >> n;
    long long ans = qpow(a*b%mod*c%mod,qpow(2,n,mod-1),mod);
    cout << ans << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Func();
    }
    return 0;
}
