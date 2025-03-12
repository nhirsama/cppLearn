#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
int lowbit(int xfirst) { return xfirst & -xfirst; }

void Solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    ll ans = 0;
    int l = r1 - l1, r = r2 - l2;
    l = l|r;
    while (l) {
        ans += lowbit(l);
        l -= lowbit(l);
    }
    // while (r) {
    //     ans += lowbit(r);
    //     r -= lowbit(r);
    // }
    cout << ans << endl;
}

int main() {
    IOS
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
