//P2527 [SHOI2001] Panda的烦恼
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
    vector<i64> arr(n + 1), ans, ne(n + 1);
    set<i64> s;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    i32 cnt = 0;
    ans.push_back(1);
    while (cnt <= k) {
        i64 minn = 0x3f3f3f3f3f3f3f3f, num = 0;
        for (i32 i = 1; i <= n; i++) {
            i64 t = arr[i] * ans[ne[i]];
            if (t < minn) {
                num = i;
                minn = t;
            }
        }
        if (s.find(minn) == s.end()) {
            ans.push_back(minn);
            s.insert(ans.back());
            cnt++;
        }
        ne[num]++;
    }
    cout << ans[k];
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
