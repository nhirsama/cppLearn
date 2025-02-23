//P11798 【MX-X9-T2】『GROI-R3』XOR
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

inline ll read() {
    ll ans = 0;
    bool flag = false;
    char c = cin.get();
    while (c < '0' || c > '9') {
        if (c == '-') flag = true;
        c = cin.get();
    }
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = cin.get();
    if (flag) return -ans;
    return ans;
}

ll l, r, k,x, n;

int getxorsum(int i) {
    if (i % 4 == 3) return 0;
    if (i % 4 == 0) return i;
    if (i % 2 == 0) return i + 1;
    return 1;
}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> l >> r >> k >> x;
        n = x ^ getxorsum(k - 1);
        if (n == 0 || n == 1) {
            bool flag = false;
            for (int i = l; i <= r; i++) {
                if (getxorsum(i) == n) {
                    cout << i << endl;
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
        } else {
                if (l <= n && n <= r && n%4 == 0) {
                    cout << n << endl;
                    continue;
                }
                n--;
                if (l <= n && n <= r && n%4 == 2) {
                    cout << n << endl;
                    continue;
                }
        }
        cout << -1 << endl;
    }
    return 0;
}
