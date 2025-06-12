//  G. Rock-Paper-Scissors
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    i32 n, r1, s1, p1, r2, s2, p2;
    std::cin >> n >> r1 >> s1 >> p1 >> r2 >> s2 >> p2;
    i32 max = 0, min = 0;
    i32 n1 = n, r11 = r1, s11 = s1, p11 = p1, r12 = r2, s12 = s2, p12 = p2;
    i32 tt = std::min(r11, s12);
    max += tt;
    r11 -= tt;
    s12 -= tt;

    tt = std::min(s11, p12);
    max += tt;
    s11 -= tt;
    p12 -= tt;

    tt = std::min(p11, r12);
    max += tt;
    p11 -= tt;
    r12 -= tt;

    //lose
    tt = std::min(r11, p12);
    max -= tt;
    r11 -= tt;
    p12 -= tt;

    tt = std::min(s11, r12);
    max -= tt;
    s11 -= tt;
    r12 -= tt;

    tt = std::min(p11, s12);
    max -= tt;
    p11 -= tt;
    s12 -= tt;
    std::cout << max << ' ';

    r11 = r1, s11 = s1, p11 = p1, r12 = r2, s12 = s2, p12 = p2;
    max = 0;
    tt = std::min(r12, s11);
    max -= tt;
    r12 -= tt;
    s11 -= tt;

    tt = std::min(s12, p11);
    max -= tt;
    s12 -= tt;
    p11 -= tt;

    tt = std::min(p12, r11);
    max -= tt;
    p12 -= tt;
    r11 -= tt;

    //lose
    tt = std::min(r12, p11);
    max += tt;
    r12 -= tt;
    p11 -= tt;

    tt = std::min(s12, r11);
    max += tt;
    s12 -= tt;
    r11 -= tt;

    tt = std::min(p12, s11);
    max += tt;
    p12 -= tt;
    s11 -= tt;
    std::cout << max << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}