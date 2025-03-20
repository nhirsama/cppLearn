//P2311 loidc，想想看
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i64, i64> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

void nhir() {
    i64 n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    i64 r = 1;
    deque<pii> q;
    i64 m;
    cin >> m;
    for (i32 i = 1; i <= m; i++) {
        i64 x,y;
        cin >> x >> y;
        while ((!q.empty()) && q.front().y < x) {
            q.pop_front();
        }
        for (r = max(x, r); r <= y; r++) {
            while (!q.empty() && q.front().x < a[r]) q.pop_front();
            q.push_front(pii(a[r], r));
        }

        cout << q.front().y << endl;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    while (T--) nhir();
    return 0;
}
