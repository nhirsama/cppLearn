//  B. Gorilla and the Exam
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::map<i32, i32> m;
    for (i32 i = 0; i < n; i++) {
        i32 a;
        std::cin >> a;
        m[a]++;
    }
    std::vector<i32> v;
    for (auto [x, y]: m) {
        v.push_back(y);
    }
    std::ranges::sort(v, std::greater());
    while (v.size() > 1 && v.back() <= k) {
        k -= v.back();
        v.pop_back();
    }
    std::cout << v.size() << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}