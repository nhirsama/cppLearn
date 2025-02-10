#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;

void Func() {
    ll n, l, r;
    cin >> n >> l >> r;
    priority_queue<ll, vector<ll>, greater<> > q2,q1;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        if (i<=r) q1.push(x);
        if (i>=l) q2.push(x);
    }
    ll ans = 0,ans2 = 0;
    for (ll i = 1; i <= r-l+1; i++) {
        ans += q1.top();
        q1.pop();
        ans2 += q2.top();
        q2.pop();
    }
    cout << min(ans,ans2) << endl;
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
