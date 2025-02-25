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

void Func() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << endl;
    } else if (n == 2) {
        cout << k << ' ' << k << endl;
    } else {
        if (n & 1) {
            cout << k << ' ';
            for (int i = 2; i < n; i++) {
                cout << 0 << ' ';
            }
            cout << k << endl;
        } else {
            for (int i = 1; i <= n; i++) {
                cout << k << ' ';
            }
            cout << endl;
        }
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
        Func();
    }
    return 0;
}
