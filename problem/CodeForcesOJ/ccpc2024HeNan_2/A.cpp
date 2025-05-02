#include <bits/stdc++.h>
using i64 = long long;

i64 get10(i64 a) {
    if (a) return 10 * get10(a / 10);
    return 1;
}

void nhir() {
    i64 n, d;
    std::cin >> n >> d;
    i64 res = (1234567890ll + d) * get10(n);
    res += (n - res % n);
    std::cout << res / n << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _;
    std::cin >> _;
    while (_--) {
        nhir();
    }
}
