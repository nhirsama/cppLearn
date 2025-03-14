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

void Solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    ll ans = k/2+1;
    if (n == k) {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0)
                if (i / 2 != arr[i]) {
                    ans = i / 2;
                    break;
                }
        }
        cout<<ans<<endl;
    } else {
        for (int i = 2; i <= n - k + 2; i++) {
            if (arr[i] != 1) {
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
        return;
    }
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
