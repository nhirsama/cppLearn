//P2311 loidc，想想看
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
    i64 n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    i64 l = 1, r = 1;
    queue<pii> q;
    i64 m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        i32 x,y;
        cin >> x >> y;
        for (; r <= y; r++) {
            if (q.empty()) {
                q.push(pii(x, r));
            } else
                while ((!q.empty()) && q.front().x < a[r]) {
                    q.pop();
                    q.push(pii(x, r));
                }
        }
        while (!q.empty() && q.front().y < x) {
            q.pop();
        }
        cout << q.front().x << endl;
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
