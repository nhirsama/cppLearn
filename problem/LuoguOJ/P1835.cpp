//P1835 素数密度
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e6 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long
i64 mul(i64 a, i64 b, i64 m) {
    i64 r = a * b - m * i64(1.L / m * a * b);
    return r - m * (r >= m) + m * (r < 0);
}
i64 pow(i64 a, i64 b, i64 m) {
    i64 res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m)) {
        if (b & 1) res = mul(res, a, m);
    }
    return res;
}
bool isprime(i64 n) {
    if (n < 2 || n % 6 % 4 != 1) {
        return (n | 1) == 3;
    }
    i64 s = __builtin_ctzll(n - 1), d = n >> s;
    for (i64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        i64 p = pow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--) {
            p = mul(p, p, n);
        }
        if (p != n - 1 && i != s) return false;
    }
    return true;
}
void nhir() {
    vector<i32> arr(N);
    i64 l,r,ans = 0;
    cin>>l>>r;
    for(i32 i = l;i<=r;i++){
        if(isprime(i)) ans++;
    }
    cout<<ans<<endl;

}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        cin >> T;
    }

    while (T--) nhir();
    return 0;
}
