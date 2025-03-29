//C
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i32 n;
    std::cin >> n;
    std::priority_queue<i64> odd, even;
    for (i32 i = 0; i < n; i++) {
        i64 x;
        std::cin >> x;
        if (x % 2 == 0) {
            even.push(x);
        } else {
            odd.push(x);
        }
    }
    while (even.size() && odd.size()) {
        i64 t = odd.top() + even.top();
        odd.pop();
        even.pop();
        if (odd.size() && odd.top() > 1) {
            t--;
            even.push(t);
            odd.push(1);
        } else {
            odd.push(t);
        }
    }
    i64 ans = 0;
    if (even.size()) {
        ans = even.top();
    }
    if (odd.size()) {
        ans = std::max(ans, odd.top());
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
