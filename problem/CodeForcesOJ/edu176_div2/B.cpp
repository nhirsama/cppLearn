//模板
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

void nhir() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n + 1);
    for (i32 i = 1; i <= n; i++) {
        cin >> a[i];
    }
    i64 ans = 0;
    if (k == 1) {
        ans = a[1] + a[n];
        for (i32 i = 2; i < n; i++) {
            ans = max(ans, a[i] + max(a[1], a[n]));
        }
    } else {
        sort(a.begin() + 1, a.end());
        for (i32 i = n; i >= n - k; i--) {
            ans += a[i];
        }
        // for (i32 i = 1; i < n - 2; i++) {
        //     if (ans < a[i] + a[i + 1] + a[i + 2]) {
        //         ans = a[i] + a[i + 1] + a[i + 2];
        //         be = i;
        //     }
        // }
        // a[be] = a[be + 1] = a[be + 2] = 0;
        // sort(all1(a));
        // for (i32 i = n; i > n - k + 2; i--) {
        //     ans += a[i];
        // }
    }
    cout << ans << endl;
}

signed main() {
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
