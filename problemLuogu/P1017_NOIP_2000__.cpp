//  P1017 [NOIP 2000 提高组] 进制转换
//  00:56
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Luogu"};

void nhir() {
    int a, b;
    std::cin >> a >> b;
    std::cout << a << '=';
    std::vector<int> v;
    while (a) {
        int t = a % b;
        a /= b;
        if (t < 0) {
            a++;
            t -= b;
        }
        v.push_back(t);
    }
    for (int i = v.size() - 1; ~i; i--) {
        if (0 <= v[i] && v[i] <= 9) {
            std::cout << char(v[i] + '0');
        } else {
            std::cout << char(v[i] - 10 + 'A');
        }
    }
    std::cout << "(base" << b << ')';
    // std::cout << s << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        // std::cin >> T;
        while (T--) nhir();
    return 0;
}
