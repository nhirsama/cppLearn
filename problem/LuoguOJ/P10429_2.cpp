//P10429 [蓝桥杯 2024 省 B] 拔河
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
    multiset<i64> mu;
    i64 n;
    cin >> n;
    vector<i64> arr(n + 1);
    for (i32 i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for (i32 i = 1; i <= n; i++) {
        for (i32 j = i; j <= n; j++) {
            mu.insert(arr[j] - arr[i - 1]);
        }
    }
    i64 ans = 0x3f3f3f3f3f3f3f3f;
    for (i32 i = 1; i <= n; i++) {
        for (i32 j = i; j <= n; j++) {
            auto t = mu.find(arr[j] - arr[i - 1]);
            mu.erase(t);
        }
        for (i32 j = 1; j <= i; j++) {
            i64 sum = arr[i] - arr[j - 1];
            auto p = mu.lower_bound(sum);
            if (p != mu.end()) {
                ans = min(ans, *p - sum);
            }
            if (p != mu.begin()) {
                ans = min(ans, sum - *--p);
            }
        }
    }
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
