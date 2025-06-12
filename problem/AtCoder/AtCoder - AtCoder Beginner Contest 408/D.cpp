//  Two Coins
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'
using arr2 = std::array<i32, 2>;

void nhir() {
    i32 n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnt = 0;
    for (char c: s) if (c == '1') cnt++;
    int tot = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int v = (s[i] == '1' ? +1 : -1);
        tot = std::max(tot + v, 0);
        ans = std::max(ans, tot);
    }
    std::cout << (cnt - ans) << endl;
    //    s += "____";
//    std::stack<arr2> st;
//    i32 cnt = 0;
//    i32 ans = 0;
//    bool one = false;
//    for (i32 i = 0; i < n; i++) {
//        cnt++;
//        if (s[i] == '1') one = true;
//        if (s[i] != s[i + 1]) {
//            if (st.empty() && s[i] == '0') {
//                cnt = 0;
//                break;
//            }
//            while (!st.empty() && (st.top()[0] < cnt || (st.top()[0] == cnt && st.top()[1] == 0))) {
//                if (st.top()[1] == 1) ans += st.top()[0];
//                st.pop();
//            }
//            st.push({cnt, s[i] - '0'});
////            std::cout << cnt << endl;
//            cnt = 0;
//        }
//    }
//    while (!st.empty()) {
//        if (st.top()[1] == 0) ans += st.top()[0];
//        st.pop();
//    }
//    if (!one) {
//        std::cout << 0 << endl;
//        return;
//    }
//    std::cout << ans << endl;
//    i32 ans = 0x3f3f3f3f3f3;
//    std::vector<i32> dp(n + 1);
//    for (i32 i = 0; i < n; i++) {
//        dp[i + 1] = dp[i] + (s[i] == '1');
//    }
//    i32 cnt0 = 0, cnt1 = 0;
//    for (auto i: s) {
//        if (i == '1')
//    }
//    std::string ss = s;
//    while (ss.size() && ss.back() == '0') ss.pop_back();
//    i32 cnt1 = -1;
//    for (auto i: ss) {
//        if (i == '1' && cnt1 == -1) cnt1++;
//        else if (i == '0' && cnt1 != -1) cnt1++;
//    }
//    i32 cnt0 = -1;
//    ss = s;
//    while (ss.size() && ss.back() == '1') ss.pop_back();
//    for (auto i: ss) {
//        if (i == '0' && cnt0 == -1) cnt0++;
//        else if (i == '1' && cnt0 != -1) cnt0++;
//    }
//    std::cout << std::min(cnt0, cnt1) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}