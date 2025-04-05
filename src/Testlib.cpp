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
    std::vector<i32> a(n + 1), b(n + 1);
    bool flag = (n % 2 == 0);
    for (i32 i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (i32 i = 1; i <= n; i++) {
        std::cin >> b[i];
    }
    for (i32 i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            if (flag) {
                std::cout << -1 << endl;
                return;
            }
            flag = true;
        }
    }
    std::vector<i32> arr(n + 1);
    for (i32 i = 1; i <= n; i++) {
        if (arr[std::min(a[i], b[i])] == 0) {
            arr[std::min(a[i], b[i])] = std::max(a[i], b[i]);
        } else if (arr[std::min(a[i], b[i])] != std::max(a[i], b[i])) {
            std::cout << -1 << endl;
            return;
        }
    }
    std::vector<pii> ans;
    std::vector<i32> yq(n + 1);
    i32 l = 1, r = n;
    for (i32 i = 1; i <= n && l < r; i++) {
        if (a[i] == b[i]) {
            yq[(n + 1) / 2] = a[i];
        } else {
            yq[l++] = a[i];
            yq[r--] = b[i];
        }
    }
    for (i32 i = 1; i <= n; i++) {
        if (yq[i] == a[i]) continue;
        for (i32 j = i + 1; j <= n; j++) {
            if (yq[i] == a[j]) {
                ans.emplace_back(i, j);
                std::swap(a[i], a[j]);
            }
        }
    }
    std::cout << ans.size() << endl;
    for (auto [x,y]: ans) {
        std::cout << x << " " << y << endl;
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
