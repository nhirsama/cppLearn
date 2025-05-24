//  UVA10288 优惠券 Coupons
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
//#define endl '\n'


void nhir(i32 n) {
    i32 fm = 1, fz = 1;
    for (i32 i = 2; i <= n; i++) {
        fz = fz * i + fm;
        fm *= i;
        i32 gcd = std::__gcd(fz, fm);
        fz /= gcd;
        fm /= gcd;
    }
    fz *= n;
    //std::cout << fz << ' ' << fm << std::endl;
    i32 gcd = std::__gcd(fz, fm);
    fz /= gcd;
    fm /= gcd;
    i32 zz = fz / fm;
    fz = fz % fm;
    if (fz == 0) {
        std::cout << zz << std::endl;
        return;
    }
//        if (zz == 0) {
//            i32 kg = log10(fm);
//            std::cout << fz << '\n';
//            for (i32 i = 0; i < kg; i++) {
//                std::cout << ' ';
//            }
//            std::cout << '\n' << fm << std::endl;
//        }
    i32 kg = log10(zz) + 1;
    //std::cout << kg << std::endl;
    for (i32 i = 0; i <= kg; i++) {
        std::cout << ' ';
    }
    std::cout << fz << '\n' << zz << ' ';
    for (i32 i = 0; i < log10(fm) + (fm == 10); i++) std::cout << '-';
    std::cout << '\n';
    for (i32 i = 0; i <= kg; i++) {
        std::cout << ' ';
    }
    std::cout << fm << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i32 n;
    while (std::cin >> n) nhir(n);
    return 0;
}