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

void Solve() {
    int n;
    cin >> n;
    vector arr(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)cin >> arr[i][j];
    }
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = n; j; j--) {
            if (arr[i][j] == 1)cnt[i]++;
            else break;
        }
    }
    sort(cnt.begin() + 1, cnt.end());
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] >= ans) ans++;
    }
    cout << (ans == n+1 ? n : ans) << endl;
    return;
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
