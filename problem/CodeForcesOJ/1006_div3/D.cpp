#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2006;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' ' <<
typedef pair<int, int> pii;
int dp[N][N];
void Func() {
    int n;
    cin >> n;
    vector<int> v(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int l = 1, r = 1, cnt = 0;
    int maxl = 1, maxr = 1, maxv = 0;
    for (; l < n; l++) {
        for (r = l; r <= n; r++) {
            if (v[r] < v[l]) {
                cnt++;
                if (cnt > maxv) {
                    maxv = cnt;
                    maxl = l;
                    maxr = r;
                }
                // else if (cnt == maxv) {
                //     maxl = min(maxl,l);
                //     maxr = max(maxr,r);
                // }
            }
        }
        cnt = 0;
    }
    cout << maxl << ' ' << maxr << endl;
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
