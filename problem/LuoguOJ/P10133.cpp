//P10133 [USACO24JAN] Balancing Bacteria B
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        //freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> arr(n + 1), d1(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = n; i; i--) {
        d1[i] = arr[i] - arr[i - 1];
    }
    ll ans = 0;
    for (int i = n; i; i--) {
        ans += abs(d1[i] - d1[i - 1]);
    }
    cout << ans << endl;
    return 0;
}
