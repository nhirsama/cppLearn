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
    std::vector<i32> a(n), b(n);
    for (auto &i: a) std::cin >> i;
    for (auto &i: b) std::cin >> i;
    std::vector<i32> c(n + 1);
    for (i32 i = 0; i < n; i++) {
        c[a[i]] = i;
    }

    std::vector<bool> st(n);
    std::vector<pii> p;
    i32 mid = -1;

    for (i32 i = 0; i < n; i++) {
        if (st[i]) continue;
        if (a[i] == b[i]) {
            if (mid == -1 && (n & 1)) {
                mid = i;
                st[i] = true;
            } else {
                std::cout << -1 << "\n";
                return;
            }
        } else {
            i32 j = c[b[i]];
            if (i == j || st[j] || a[j] == b[j] || b[j] != a[i]) {
                std::cout << -1 << "\n";
                return;
            }
            st[i] = st[j] = true;
            p.push_back({i, j});
        }
    }

    std::vector<i32> yq(n, -1);
    i32 l = 0, r = n - 1;
    for (auto [x, y]: p) {
        yq[l++] = x;
        yq[r--] = y;
    }
    if (n & 1) yq[l] = mid;

    std::vector<i32> aa(n);
    for (i32 i = 0; i < n; i++) aa[i] = i;
    std::vector<i32> pos(n);
    for (i32 i = 0; i < n; i++) pos[aa[i]] = i;

    std::vector<pii> ans;
    for (i32 i = 0; i < n; i++) {
        if (aa[i] != yq[i]) {
            i32 j = pos[yq[i]];
            std::swap(aa[i], aa[j]);
            pos[aa[i]] = i;
            pos[aa[j]] = j;
            ans.push_back({i + 1, j + 1});
        }
    }

    std::cout << ans.size() << endl;
    for (auto [x, y]: ans) {
        std::cout << x << " " << y << endl;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
