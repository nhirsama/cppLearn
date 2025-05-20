//  E. Romantic Glasses
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
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    std::vector<i32> preeven(n + 1), preodd(n + 1);
    for (i32 i = 0; i < n; i++) {
        preeven[i + 1] = preeven[i] + ((i + 1) & 1 ? 0 : v[i]);
        preodd[i + 1] = preodd[i] + ((i + 1) & 1 ? v[i] : 0);
    }
    std::set<i32> s;
    for (i32 i = 0; i <= n; i++) {
        i32 t = preeven[i] - preodd[i];
        if (s.find(t) != s.end()) {
            std::cout << "YES\n";
            return;
        }
        s.insert(t);
    }
    std::cout << "NO\n";
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
