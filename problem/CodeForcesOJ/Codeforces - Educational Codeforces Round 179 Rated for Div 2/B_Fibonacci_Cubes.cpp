//  B. Fibonacci Cubes
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
std::vector<i32> fib(15);

void nhir() {
    std::string s;
    i32 n, m;
    std::cin >> n >> m;
    for (i32 i = 0; i < m; i++) {
        i32 x, y, z;
        std::cin >> x >> y >> z;
        if (x >= fib[n] + fib[n - 1] && y >= fib[n] && z >= fib[n]) {
            s.push_back('1');
        } else if (y >= fib[n] + fib[n - 1] && x >= fib[n] && z >= fib[n]) {
            s.push_back('1');
        } else if (z >= fib[n] + fib[n - 1] && y >= fib[n] && x >= fib[n]) {
            s.push_back('1');
        } else s.push_back('0');
    }
    std::cout << s << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    fib[1] = 1, fib[0] = 1;
    for (i32 i = 2; i < 15; i++) fib[i] = fib[i - 2] + fib[i - 1];
    std::cin >> T;
    while (T--) nhir();
    return 0;
}