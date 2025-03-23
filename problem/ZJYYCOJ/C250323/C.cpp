//模板
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
    i64 n,x,y;
    cin >> n >> x >> y;
    if (x + y > n + 1 || x > n || y > n || x * y < n) {
        cout << "NO" << endl;
    } else {
        vector<i32> ans;
        cout << "YES" << endl;
        i64 a = 0, b = n - x + 1;
        i64 other = n - x, cnt = 0;
        for (i32 i = 1; i <= x; i++) {
            ans.push_back(b++);
            i32 none = min(other - cnt,y - 1);
            for (i32 j = none; j; j--) {
                ans.push_back(a + j);
                cnt++;
            }
            a += none;
        }
        for (i32 i = 0; i < ans.size(); i++) {
            cout << ans[i] << " \n"[i + 1 == ans.size()];
        }
    }
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
