//  P3812 【模板】线性基
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> arr(n);
    for (auto &i: arr) std::cin >> i;
    i32 k = 0;
    for (i32 i = 62; ~i; i--) {
        for (i32 j = k; j < n; j++) {
            if (arr[j] >> i & 1) {
                std::swap(arr[j], arr[k]);
                break;
            }
        }
        if ((arr[k] >> i & 1) == 0) continue;
        for (i32 j = 0; j < n; j++) {
            if (j != k && (arr[j] >> i & 1)) arr[j] ^= arr[k];
        }
        k++;
        if (k == n) break;
    }
    i32 ans = 0;
    for (i32 i = 0; i < k; i++) {
        ans ^= arr[i];
        std::cout << arr[i] << endl;
    }

    std::cout << ans << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
