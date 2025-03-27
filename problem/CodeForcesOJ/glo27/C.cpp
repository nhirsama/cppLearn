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
    int n;
    cin >> n;
    if (n & 1) {
        cout << n << endl;
        for (int i = 2; i < n - 1; i++) {
            if (i == 3) continue;
            std::cout << i << ' ';
        }
        std::cout << "1 3 " << n - 1 << ' ' << n << endl;
    } else {
        int y = (1 << ((int) log2(n) + 1)) - 1;

        if (n == (n & -n)) {
            cout << y << endl;
            for (int i = 2; i < n - 2; i++) {
                cout << i << ' ';
            }
            cout << 1 << ' ' << n - 2 << ' ' << n - 1 << ' ' << n << endl;
        } else {
            cout << y << endl;
            int z = n ^ y;
            for (int i = 1; i < n; i++) {
                if (i == z || i == (y >> 1)) continue;
                cout << i << ' ';
            }
            cout << (y >> 1) << ' ' << z << ' ' << n << endl;
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
        Solve();
    }
    return 0;
}
