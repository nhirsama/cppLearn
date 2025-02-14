//T573804 [语言月赛 202502] 随机数
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    const ll MAX = 1e6;
    const ll MIN = -1e6;
    ll n, l, r;
    cin >> n >> l >> r;
    ll ans = 0;
    vector<ll> v(n, 0);
    if (r < 0) {
        for (ll i = 0; i < n; i++) {
            if (ans > r) v[i] = max(MIN, r - ans);
            else if (ans < l) v[i] = min(MAX, l - ans);
            else v[i] = 0;
            ans += v[i];
        }
    } else if (l > 0) {
        for (ll i = 0; i < n; i++) {
            if (ans < l) v[i] = min(MAX, l - ans);
            else if (ans > r) v[i] = max(MIN, r - ans);
            else v[i] = 0;
            ans += v[i];
        }
    }
    for (int i: v) {
        cout << i << " ";
    }
    return 0;
}
