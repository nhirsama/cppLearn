//G1
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
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
    }
    std::vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cout << "? 1 1 " << i << std::endl;
        std::cin >> b[i];
    }
    if (abs(b[1]) % 2 == 1) {
        std::cout << "! " << b[1] << ' ';
        for (int i = 2; i <= n; i++) {
            std::cout << b[i] - b[1] << ' ';
        }
        std::cout << std::endl;
        return;
    }
    std::cout << "? 2 1" << std::endl;
    int p1;
    std::cout << "? 1 1 1" << std::endl;
    std::cin >> p1;
    p1 -= b[1];
    std::vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + b[i];
    }

    auto check = [&](int l, int r) {
        std::cout << "? 1 " << r - l + 1;
        for (int i = l; i <= r; i++) std::cout << " " << i;
        std::cout << std::endl;
        int sum;
        std::cin >> sum;
        return sum - pre[r] + pre[l - 1] != (r - l + 1) * p1;
    };

    int l = 2, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(l, mid)) r = mid;
        else l = mid + 1;
    }
    std::vector<int> a(n + 1);
    a[l] = b[l];
    a[1] = a[l] - b[1];
    for (int i = 2; i <= n; i++) {
        if (i == l) continue;
        a[i] = b[i] - b[1];
    }
    std::cout << "! ";
    for (int i = 1; i <= n; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
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
