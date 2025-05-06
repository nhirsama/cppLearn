//  B. Apples in Boxes

#include<bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
using pii = std::pair<i32, i32>;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::vector<i32> v(n);
    i32 sum = 0;
    for (auto &i: v) std::cin >> i, sum += i;
    i32 ma = *std::max_element(v.begin(), v.end());
    i32 mi = *std::min_element(v.begin(), v.end());
    i32 mac = std::count(v.begin(), v.end(), ma);
    i32 mic = std::count(v.begin(), v.end(), mi);
    if (ma - mi > k + 1) {
        std::cout << "Jerry\n";
    } else if (ma - mi == k + 1 && mac > 1) {
        std::cout << "Jerry\n";
    } else {
        if (sum & 1) std::cout << "Tom\n";
        else std::cout << "Jerry\n";
    }
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
