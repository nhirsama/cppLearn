//Tokitsukaze and Multiple
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

void base_e() {
    i64 n, p;
    cin >> n >> p;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= p;
    }
    i64 ans = 0, sum = 0;
    set<i64> s;
    s.insert(0);
    for (i32 i = 1; i <= n; i++) {
        sum = (sum + a[i]) % p;
        if (s.count(sum)) {
            ans++;
            s.clear();
        }
        s.insert(sum);
    }
    cout << ans << endl;
}

signed main() {
    IOS;
    i32 t;
    cin >> t;
    while (t--) {
        base_e();
    }
    return 0;
}
