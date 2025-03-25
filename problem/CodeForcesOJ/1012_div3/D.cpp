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
    i64 n, m, k;
    cin >> n >> m >> k;
    i64 l = 1, r = m, ans = m;
    auto check = [&](i64 mid)-> bool {
        i64 minn = min((mid * (m + 1)) / (mid + 1), m);
        i64 max1;
        if (minn >= (m + 1) / 2 + 1) {
            max1 = minn;
        } else {
            max1 = (m + 1) / 2;
        }
        return max1 * n >= k;
    };
    while (l < r) {
        i64 mid = (l + r) >> 1;

        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << endl;
}

signed main() {
    ;
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
