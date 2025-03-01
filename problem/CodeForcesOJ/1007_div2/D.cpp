#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

int getxor(long long m, vector<int> &sum, int n) {
    int ret = 0;
    while (true) {
        if (m <= n * 2) {
            ret ^= sum[m] ^ sum[m - 1];
            break;
        }
        ret ^= sum[n];
        long long a = m / 2;
        if (a & 1) {
            break;
        }
        m /= 2;
    }
    return ret;
}

void Solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<int> arr(n + 1), xorsum(n + 1);
    for (int i = 1; i <= n; i++)cin >> arr[i], xorsum[i] = xorsum[i - 1] ^ arr[i];
    if (n % 2 == 0) {
        arr.push_back(xorsum[n / 2]);
        xorsum.push_back(arr[n + 1] ^ xorsum[n]);
        n++;
    }
    for (int i = n + 1; i <= n * 2; i++) {
        arr.push_back(xorsum[i / 2]);
        xorsum.push_back(xorsum[i - 1] ^ arr[i]);
    }
    cout << getxor(l, xorsum, n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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
