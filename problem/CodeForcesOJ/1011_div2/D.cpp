//D
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

void nhir() {
    i64 n, k;
    cin >> n >> k;
    i64 ans = 0;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    std::priority_queue<i64> pq;
    for (int i = 1; i <= n; i++) {
        pq.push(a[i]);
        if ((n - i + 1) % (k + 1) == 0) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
}

signed main() {
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
