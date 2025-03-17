//B3645 数列前缀和 2
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
constexpr int mod = 1145141;

i64 power(i64 a, i64 b, i32 p) {
    i64 res = 1;
    for (; b; b /= 2, a = a * a % p) {
        if (b % 2) {
            res = res * a % p;
        }
    }
    return res;
}

signed main() {
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    IOS;
    i64 n, q;
    cin >> n >> q;
    vector<i64> arr(n + 1), narr(n + 1);
    arr[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] = (arr[i] * arr[i - 1]) % mod;
    }
    for (int i = 0; i <= n; i++) {
        narr[i] = power(arr[i], mod - 2, mod);
    }
    i64 ans = 0;
    while (q--) {
        i32 l, r;
        cin >> l >> r;
        ans ^= arr[r] * narr[l - 1] % mod;
    }
    cout << ans << endl;
    return 0;
}
