//C. Two Colors
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
    i64 n, m;
    cin >> n >> m;
    vector<i64> v(max(n,m) + 2), arr(max(n,m) + 2);
    for (int i = 1; i <= m; i++) {
        i64 x;
        cin >> x;
        arr[i] = x;
        v[1] += 1;
        v[x + 1] -= 1;
    }
    for (int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
    }
    i64 ans = 0;
    for (int i = 1; i < n ;i++) {
        ans += v[i] * v[n - i]-min(v[i],v[n-i]);
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
