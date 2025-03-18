//A. To Zero
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
    i64 n, m;
    cin >> n >> m;
    i64 cnt = 0;
    if (n & 1) {
        if (m & 1) {
            cnt++;
            n -= m;
        } else {
            n -= m;
            cnt++;
        }
    } else {
        cnt++;
        if (m & 1) {
            n -= m - 1;
        } else {
            n -= m;
        }
    }
    if (m & 1) m--;
    cnt += n / m;
    if (n % m) cnt++;
    cout << cnt << endl;
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
