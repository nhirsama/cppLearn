//  E. Final Countdown
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<i32> pre(n);
    for (i32 i = 0; i < n; i++) {
        pre[i] = (i ? pre[i - 1] : 0) + s[i] - '0';
    }
    std::string ans;
    i32 base = 0;
    for (i32 i = n - 1; ~i; i--) {
        base += pre[i];
        ans.push_back(base % 10 + '0');
        base /= 10;
    }
    ans.push_back(base % 10 + '0');
    while (ans.size() && ans.back() == '0') ans.pop_back();
    for (i32 i = ans.size() - 1; ~i; i--) {
        std::cout << ans[i];
    }
    std::cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}