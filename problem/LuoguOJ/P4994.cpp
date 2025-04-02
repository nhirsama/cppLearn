//P4994 终于结束的起点
#include <bits/stdc++.h>
using i64 = long long int;
using i32 = int;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
void nhir() {
    i64 arr[2] = {0, 1};
    i64 n;
    std::cin >> n;
    for (i32 i = 2; i <= n * n; i++) {
        arr[i & 1] = (arr[0] + arr[1]) % n;
        if (arr[i & 1] == 1 && arr[1 - (i & 1)] == 0) {
            std::cout << i - 1 << std::endl;
            return;
        }
    }
    std::cout << 0 << std::endl;
}

signed main() {
    IOS;
    i32 T = 1;

    while (T--) nhir();
    return 0;
}