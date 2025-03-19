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
    i64 k;
    i64 nana = 0;
    cin >> k;
    for (i64 i = 1; i <= k; i++) {
        nana = ((nana << 3) + (nana << 1) + 7) % k;
        if (nana == 0) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}

signed main() {
    ;
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
