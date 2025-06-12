//  B. Slice to Survive
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n, m, a, b;
    std::cin >> n >> m >> a >> b;
    i32 aa = std::min(a, n - a + 1);
    i32 bb = std::min(b, m - b + 1);
    i32 ans = 0x3f3f3f3f3f3f3f;
    i32 nt = aa, mt = m;
    i32 res = 1;
    while (nt != 1) nt = (nt + 1) / 2, res++;
    while (mt != 1) mt = (mt + 1) / 2, res++;
    ans = std::min(ans, res);
    nt = n, mt = bb;
    res = 1;
    while (nt != 1) nt = (nt + 1) / 2, res++;
    while (mt != 1) mt = (mt + 1) / 2, res++;
    ans = std::min(ans, res);
//    if (aa * m <= bb * n) {
//        n = aa;
//    } else m = bb;
//    while (n != 1 || m != 1) {
//        aa = (n + 1) / 2;
//        bb = (m + 1) / 2;
//        if (aa * m <= bb * n) {
//            n = aa;
//            ans++;
//        } else m = bb, ans++;
//    }

    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}