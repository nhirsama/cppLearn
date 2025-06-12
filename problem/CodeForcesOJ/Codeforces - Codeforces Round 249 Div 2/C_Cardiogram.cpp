//  C. Cardiogram
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    i32 sum = 0;
    for (auto &i: v)std::cin >> i, sum += i;

    std::vector g(3000, std::string(sum, ' '));
    i32 begin = 1500;
    i32 it = 0;
    for (i32 i = 0; i < n; i++) {
        char c = (i & 1) ? '\\' : '/';
        for (i32 j = 0; j < v[i]; j++) {
            g[begin][it++] = c;
            if (j != v[i] - 1) begin += ((i & 1) ? 1 : -1);
        }
    }
    for (auto &i: g) {
        if (i.contains('\\') || i.contains('/')) {
            std::cout << i << endl;
        }
    }
//    i32 maxit = std::ranges::max_element(v) - v.begin();
//    i32 beg = 0;
//    for (i32 i = maxit - 1; i >= 0; i--) {
//        beg += ((i & 1) ? -1 : 1) * v[i];
//    }
//    if (maxit == 0) beg = v[0];
//    std::vector<std::string> ans(v[maxit]);
//    auto add = [&](i32 p, char c) -> void {
//        for (i32 i = 0; i < v[maxit]; i++) {
//            //std::cout<<p<<endl;
//            if (i == p) ans[i].push_back(c);
//            else ans[i].push_back(' ');
//        }
//    };
//    for (i32 i = 0; i < n; i++) {
//        for (i32 j = 0; j < v[i]; j++) {
//            beg += ((i & 1) ? 1 : -1);
//            add(beg, (i & 1) ? '\\' : '/');
//        }
//        beg += ((i & 1) ? 1 : -1);
//    }
//    for (auto &s: ans) {
//        std::cout << s << endl;
//    }
    //std::cout << beg << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}