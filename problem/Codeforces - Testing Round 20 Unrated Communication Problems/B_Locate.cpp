//  B. Locate
//  18:40
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhirf() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (auto &i: v) std::cin >> i;
    for (auto i: v) {
        if (i == 1) {
            std::cout << 0 << endl;
            return;
        } else if (i == n) {
            std::cout << 1 << endl;
            return;
        }
    }
}

void nhirs() {
    int n, x;
    std::cin >> n >> x;
    int l = 1, r = n;
    if (x == 1) {
        while (l < r) {
            auto check = [&](int mid) {
                std::cout << '?' << ' ' << mid << ' ' << n << std::endl;
                int t;
                std::cin >> t;
                if (t == n - 1) {
                    return false;
                } else {
                    return true;
                }
            };
            int mid = (l + r+1) >> 1;
            if (check(mid)) {
                r = mid-1;
            } else {
                l = mid;
            }
        }
        std::cout << '!' << ' ' << l << std::endl;
    } else {
        while (l < r) {
            auto check = [&](int mid) {
                std::cout << '?' << ' ' << 1 << ' ' << mid << std::endl;
                int t;
                std::cin >> t;
                if (t == n - 1) {
                    return true;
                } else {
                    return false;
                }
            };
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        std::cout << '!' << ' ' << l << std::endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::string s;
    std::cin >> s;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    if (s == "first") while (T--) nhirf();
    else while (T--) nhirs();
    return 0;
}
