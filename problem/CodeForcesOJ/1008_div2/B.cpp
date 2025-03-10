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

void Solve() {
    int n, k;
    cin >> n >> k;
    if (k & 1) {
        for (int i = 1; i < n; i++) {
            cout << n << ' ';
        }
        cout << n - 1 << endl;
    } else {
        for (int i = 1; i < n - 1; i++) {
            cout << n - 1 << ' ';
        }
        cout << n << ' ';
        cout << n - 1 << endl;
    }
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
