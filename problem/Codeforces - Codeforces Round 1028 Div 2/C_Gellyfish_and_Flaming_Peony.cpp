//  C. Gellyfish and Flaming Peony
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
int G[5005][5005];
using namespace std;
using ll = i64;

void nhir() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    int g = a[0];
    for (int i = 1; i < n; ++i) g = std::gcd(a[i], g);
    ll cnt = std::ranges::count(a, g);
    ll ans = 1e9 + 17, now = 0;
    if (cnt) {
        cout << n - cnt << "\n";
        return;
    }
    for (int x = 0; x < n; ++x) {
        int q = a[x];
        now = 0;
        for (int i = x + 1; i < n; ++i) {
            if (x == i) continue;
            if (q != std::gcd(q, a[i])) {
                ++now;
                q = std::gcd(q, a[i]);
            }
        }
        if (q == g)
            ans = std::min(ans, now);
    }
    ans += n - 1;
    cout << ans << "\n";

    // i32 n;
    // std::cin >> n;
    // std::vector<i32> v(n);
    // for (auto &i: v) std::cin >> i;
    //
    // i32 gcd = 0;
    // for (auto i: v) gcd = G[gcd][i];
    // // for (auto &i: v) i /= gcd;
    // i32 cnt = std::ranges::count(v, gcd);
    // // std::cout << gcd << endl;
    // if (cnt) {
    //     std::cout << n - cnt << endl;
    //     return;
    // }
    // i32 min = 0x3f3f3f3f;
    // for (i32 i = 0; i < n; i++) {
    //     i32 gc = v[i];
    //     i32 now = 0;
    //     for (i32 j = i + 1; j < n; j++) {
    //         if (gc != G[gc][v[j]]) {
    //             now++;
    //             gc = G[gc][v[j]];
    //         }
    //     }
    //     if (gc == gcd) min = std::min(min, now);
    // }
    // std::cout << n + min - 1 << endl;


    // // std::cout << gcd << endl;
    // for (i32 i = 0; i < n; i++) {
    //     for (i32 j = 0; j < n; j++) {
    //     }
    // }
    // std::array<i32, 5005> ys{};
    // for (auto i: v) {
    //     for (i32 j = 1; j * j <= i; j++) {
    //         if (i % j == 0) {
    //             ys[i / j]++;
    //             if ((i / j) != j) ys[j]++;
    //         }
    //     }
    // }
    // i32 max = 0;
    // for (i32 i = 1; i <= 5000; i++) {
    //     if (ys[i] == n) max = i;
    // }
    //
    // i32 cnt = 0;
    // for (i32 i = 0; i < n; i++) {
    //     if (v[i] == max) cnt++;
    // }
    // i32 cntt = 0x3f3f3f3f3f;
    // std::cout << max << endl;
    // std::cout << cnt << endl;
    // if (cnt == 0) {
    //     i32 min = 0x3f3f3f3f;
    //     for (i32 i = 0; i < n; i++) {
    //         for (i32 j = 0; j < n; j++) {
    //             if (i == j) continue;
    //             min = std::min(min, std::gcd(v[i], v[j]));
    //         }
    //     }
    //     i32 tot = 0;
    //     for (; min != max; tot++) {
    //         for (i32 i = 0; i < n; i++) {
    //             min = std::min(min, std::gcd(v[i], min));
    //         }
    //     }
    //     std::cout << n + tot << endl;
    // } else std::cout << n - cnt << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    for (i32 i = 0; i <= 5000; i++) {
        for (i32 j = 0; j <= 5000; j++) {
            G[i][j] = std::gcd(i, j);
        }
    }
    while (T--) nhir();
    return 0;
}
