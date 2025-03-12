#define LOCAL
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
int lowbit(int xfirst) { return xfirst & -xfirst; }

void Solve() {
    int x;
    cin >> x;
    int y = (1<<(int)log2(x))-1;
    int z = x ^ y;
    if (x == lowbit(x)) cout << -1 << endl;
    else if (y + x > z && x + z > y && z + y > x) cout << y << endl;
    else cout << -1 << endl;
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
