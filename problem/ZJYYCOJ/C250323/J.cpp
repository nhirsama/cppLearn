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
    i64 n;
    cin >> n;
    vector<i64> a(n + 1);
    vector<i64> pre(n + 6);
    i64 cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt++;
        pre[0] += a[i];
        pre[cnt + 1] -= a[i];
    }
    i64 p = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1];
        if (pre[i] >= 4) {
            p++;
        }
    }
    cout << p << endl;
}

signed main() {
    IOS;
    i32 T = 1;

    while (T--) nhir();
    return 0;
}
