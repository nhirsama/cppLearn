//  C. Permutation Cycle
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'

void nhir() {
    i32 n, a, b;
    std::cin >> n >> a >> b;
    i32 x = 0, y = 0;
    for (i32 i = 0; i * a <= n; i++) {
        if ((n - i * a) % b == 0) {
            x = i, y = (n - i * a) / b;
            break;
        }
    }
    if (x == 0 && y == 0) {
        std::cout << -1 << endl;
        return;
    }
    std::deque<i32> d;
    i32 now = 1;
    for (i32 i = 0; i < x; i++) {
        for (i32 j = 0; j < a; j++) {
            d.push_back(now++);
        }
        for (i32 j = 0; j < a; j++) {
            if (j == 0) {
                std::cout << d.back() << ' ';
                d.pop_back();
            } else {
                std::cout << d.front() << ' ';
                d.pop_front();
            }
        }
    }
    for (i32 i = 0; i < y; i++) {
        for (i32 j = 0; j < b; j++) {
            d.push_back(now++);
        }
        for (i32 j = 0; j < b; j++) {
            if (j == 0) {
                std::cout << d.back() << ' ';
                d.pop_back();
            } else {
                std::cout << d.front() << ' ';
                d.pop_front();
            }
        }
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
