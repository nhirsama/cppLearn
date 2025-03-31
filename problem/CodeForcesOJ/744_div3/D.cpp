//D
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
    i64 n;
    std::cin >> n;
    std::priority_queue<pii> q;
    for (i32 i = 0; i < n; i++) {
        i32 x;
        std::cin >> x;
        if (x) q.push({x, i + 1});
    }
    std::vector<pii> ans;
    while (q.size() > 1) {
        pii a = q.top();
        q.pop();
        pii b = q.top();
        q.pop();
        ans.push_back({a.y, b.y});
        a.x--;
        b.x--;
        if (a.x) q.push(a);
        if (b.x) q.push(b);
    }
    std::cout << ans.size() << endl;
    for (auto [x,y]: ans) {
        std::cout << x << ' ' << y << endl;
    }
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
