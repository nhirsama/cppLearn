//  P1495 【模板】中国剩余定理（CRT）/ 曹冲养猪
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'
using i128 = __int128;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    i64 g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<std::array<i32, 2>> v(n);
    i64 mul = 1;
    i128 tt = 1;
    for (auto &[x, y]: v) std::cin >> x >> y, mul *= x;
    i32 ans = 0;
    for (auto [a, b]: v) {
        i32 x, y;
        i32 k = mul / a;
        exgcd(k, a, x, y);
        ans = (ans + tt * k * b % mul * x % mul) % mul;
    }
    std::cout << (ans + mul) % mul << endl;

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}