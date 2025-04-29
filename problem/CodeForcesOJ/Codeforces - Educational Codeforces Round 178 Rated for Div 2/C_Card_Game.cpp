//  C. Card Game

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
    i32 n;
    std::cin >> n;
    std::vector<i32> a, b;
    for (i32 i = 1; i <= n; i++) {
        char t;
        std::cin >> t;
        if (t == 'A') a.push_back(i);
        else b.push_back(i);
    }
    i32 max = *std::ranges::max_element(b);
    for (auto i: a) {
        if (i == 1) {
            if (b.size() == 1 && b[0] == n) {
                std::cout << "Alice\n";
                return;
            }
        } else if (i == n) {
            if (std::ranges::find(b, 1) == b.end()) {
                std::cout << "Alice\n";
                return;
            }
        } else if (i > max) {
            std::cout << "Alice\n";
            return;
        }
    }
    std::cout << "Bob\n";
    return;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
