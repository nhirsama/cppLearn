#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

void Solve() {
    int n;
    cin >> n;
    if (n == 1 || n == 3)cout << -1 << endl;
    else if (n == 2) cout << 66 << endl;
    else if (n & 1) {
        for (int i = 1; i <= n - 5; i++) cout << 3;
        cout << 36366 << endl;
    } else {
        for (int i = 1; i <= n - 4; i++) cout << 3;
        cout << 3366 << endl;
    }
}

int main() {
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
