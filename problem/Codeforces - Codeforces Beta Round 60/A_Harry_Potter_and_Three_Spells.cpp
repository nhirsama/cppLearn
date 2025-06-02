//  A. Harry Potter and Three Spells
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
using f128 = long double;

void nhir() {
    f128 a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
//    if (a == 0 || c == 0 || e == 0) {
//        if (d && (b || f)) {
//            std::cout << "Ron\n";
//            return;
//        } else {
//            std::cout << "Hermione\n";
//            return;
//        }
//    }
    f128 ab = b / a;
    f128 cd = d / c;
    f128 ef = f / e;
//    std::cout << ab << cd << ef;
//    if (cd > 1e10) {
//        std::cout << "Ron\n";
//        return;
//    }
    if (ab == 0.0 / 0.0) ab = 1.0;
    if (ef == 0.0 / 0.0) ef = 1.0;
    if (cd > 1e15) {
        std::cout << "Ron\n";
        return;
    }
    if (ab * cd > 1e15) {
        std::cout << "Ron\n";
        return;
    }
    if (ab * cd * ef > 1 + 1e-5) {
        std::cout << "Ron\n";
        return;
    } else {
        std::cout << "Hermione\n";
    }
//    f128 aa = 1e10;
//    if (e || f) aa = aa / e * f;
//    if (e == 0 && f) aa = 1e15;
//    if (a || b) aa = aa / a * b;
//    if (a == 0 && b) aa = 1e15;
//    if (c || d) aa = aa / c * d;
//    if (c == 0 && d) aa = 1e15;
//    if (aa > 1e10 && d) {
//        std::cout << "Ron\n";
//        return;
//    } else {
//        std::cout << "Hermione\n";
//        return;
//    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}