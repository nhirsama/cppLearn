#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define space << ' '
typedef pair<int, int> pii;

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1), st(n + 1);
    int maxn = 1, minn = 1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        st[v[i]] = true;
        if (v[minn] > v[i]) {
            minn = i;
        }
        if (v[maxn] < v[i]) {
            maxn = i;
        }
    }
    int nul = 0;
    for (int i = 1; i <= n; i++) {
        if (!st[i])nul = i;
    }
    int a, b;
    if (nul) {
        cout << "? " << nul << ' ' << (nul == n ? n-1 : n) << endl;
        cin >> a;
        if (a) {
            cout << "! B" << endl;
        } else {
            cout << "! A" << endl;
        }
    } else {
        cout << "? " << minn << ' ' << maxn << endl;
        cin >> a;
        cout << "? " << maxn << ' ' << minn << endl;
        cin >> b;
        if (a >= n - 1 && b >= n - 1) {
            cout << "! B" << endl;
        } else {
            cout << "! A" << endl;
        }
    }
}

signed main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
