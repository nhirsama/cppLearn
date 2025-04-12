//  P12130 [蓝桥杯 2025 省 B] 移动距离
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    //\sqrt{233^2+666^2}*\arctan{\frac{666}{233}}
    printf("%.0f",std::sqrt(666*666+233*233)*(1+std::atan(1.0*666/233)));
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}