#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
typedef long long ll;

void Func() {
    int n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &v[i]);
    }
    vector<ll> fsum(n + 2), bsum(n + 2);
    for (int i = 1; i <= n; i++) {
        if (v[i] > 0)fsum[i] = fsum[i - 1] + v[i];
    }
    for (int i = n; i; i--) {
        if (v[i] < 0)bsum[i] = bsum[i + 1] - v[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, fsum[i] + bsum[i]);
    }
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
