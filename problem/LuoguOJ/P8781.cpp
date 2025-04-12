//P8781 [蓝桥杯 2022 省 B] 修剪灌木
#include <bits/stdc++.h>
using i64 = long long int;
signed main() {
    i64 n;
    std::cin >> n;
    for (i64 i = 1; i <= n; i++) {
        std::cout << std::max((n - i) * 2, i * 2 - 2) << "\n";
    }
    return 0;
}
