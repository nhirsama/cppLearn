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
    i64 h1, h2, h3, w1, w2, w3;
    i64 ans = 0;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    i64 ma = max(h1, max(h2, max(h3, max(w1, max(w2, w3)))));
    vector<i64> arr(15);
    auto dfs = [&](auto self, i32 cnt) {
        if (cnt == 3) {
            if (arr[1] + arr[2] + arr[3] != h1) return;
        }
        if (cnt == 6) {
            if (arr[4] + arr[5] + arr[6] != h2) return;
        }
        if (cnt == 7) {
            if (arr[1] + arr[4] + arr[7] != w1) return;
        }
        if (cnt == 8) {
            if (arr[2] + arr[5] + arr[8] != w2) return;
        }
        if (cnt == 9) {
            if (arr[7] + arr[8] + arr[9] != h3) return;
            if (arr[1] + arr[4] + arr[7] != w1) return;
            if (arr[2] + arr[5] + arr[8] != w2) return;
            if (arr[3] + arr[6] + arr[9] != w3) return;
            ans++;
            return;
        }
        for (i32 i = 1; i <= ma; i++) {
            arr[cnt + 1] = i;
            self(self, cnt + 1);
        }
    };
    dfs(dfs, 0);
    cout << ans << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        cin >> T;
    }

    while (T--) nhir();
    return 0;
}
