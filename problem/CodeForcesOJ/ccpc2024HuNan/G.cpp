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
    auto swap1 = [&](i32 i,i32 j) {
        std::cout<<i+1<<' '<<j+1<<'\n';
        std::cout<<j+1<<' '<<i+1<<'\n';
        std::cout<<i+1<<' '<<j+1<<'\n';
    };
    auto swap = [&](i32 i,i32 j) {
        if (i>j) i^=j^=i^=j;
        for (i32 ii = i;ii<j;ii++) {
            swap1(ii,ii+1);
        }
        for (i32 ii = j-2;ii>=i;ii--) {
            swap1(ii,ii+1);
        }
        std::swap(arr[j],arr[i]);
    };
    for (i32 i = 20; ~i; i--) {
        for (i32 j = k; j < n; j++) {
            if (arr[j] >> i & 1) {
                swap(arr[j], arr[k]);
                break;
            }
        }
        if ((arr[k] >> i & 1) == 0) continue;
        for (i32 j = 0; j < n; j++) {
            if (j != k && (arr[j] >> i & 1)) {
                // 仅通过相邻两项的异或运算实现线性基。
                arr[j] ^= arr[k];
            }
        }
        k++;
        if (k == n) break;
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
