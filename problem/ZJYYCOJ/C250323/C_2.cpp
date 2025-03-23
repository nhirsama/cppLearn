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
    if (x + y > n + 1 || x > n || y > n) {
        cout << "NO" << endl;
    } else {
        vector<i64> ans;
        while (n) {
            for (i32 i = 0; i < y; i++)
                ans.push_back(n - y + 1 + i);
            n -= y;
            x--;
            y = min(n - x + 1,y);
        }
        cout << "YES" << endl;
        for (i32 i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " \n"[i == 0];
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
