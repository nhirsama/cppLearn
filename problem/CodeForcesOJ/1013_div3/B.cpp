//B
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
    i64 n,x;
    cin >> n >> x;
    vector<i64> a(n + 1);
    i64 cnt = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    i64 ans = 0;
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) {
        if (a[i]>=x) {
            ans++;
            cnt--;
        }
    }
    i64 cntt = 0;
    for (int i = cnt; i;i--) {
        cntt++;
        if (a[i]*cntt>=x) {
            ans++;
            cntt = 0;
        }
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
