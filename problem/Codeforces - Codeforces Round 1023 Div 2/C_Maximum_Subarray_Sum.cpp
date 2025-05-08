//  C. Maximum Subarray Sum

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
i32 INF = 1e13;

void nhir() {
    i32 n, k;
    std::string s;
    std::cin >> n >> k >> s;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    i32 p = -1;
    for (i32 i = 0; i < n; i++) {
        if (s[i] == '0') {
            p = i;
            v[i] = -INF;
        }
    }
    i32 tem = 0, max = 0;
    for (i32 i = 0; i < n; i++) {
        tem = std::max(tem + v[i], v[i]);
        max = std::max(max, tem);
    }
    if (max > k || (max != k && p == -1)) {
        std::cout << "No\n";
        return;
    }
    if (p != -1) {
        tem = 0;
        i32 pre = 0, suf = 0;
        for (i32 i = p + 1; i < n; i++) {
            tem += v[i];
            pre = std::max(pre, tem);
        }
        tem = 0;
        for (i32 i = p - 1; ~i; i--) {
            tem += v[i];
            suf = std::max(suf, tem);
        }
        v[p] = k - suf - pre;
    }
    std::cout << "Yes\n";
    for (auto &i: v) std::cout << i << ' ';
    std::cout << endl;
    // std::vector<i64> suf(n, 0), pre(n, 0);
    // for (i32 i = 0; i < n; i++) {
    //     suf[i] = s[i] == '1' ? (i ? suf[i - 1] : 0) + v[i] : 0;
    // }
    // for (i32 i = n - 1; ~i; i--) {
    //     pre[i] = s[i] == '1' ? (i + 1 < n ? pre[i + 1] : 0) + v[i] : 0;
    // }
    // i64 max = -INF;
    // for (i32 i = 0; i < n;) {
    //     if (s[i] == '1') {
    //         i64 sum = 0;
    //         while (i < n && s[i] == '1') {
    //             sum += v[i++];
    //         }
    //         max = std::max(max, sum);
    //     } else i++;
    // }
    // if (std::find(all(s), '0') == s.end()) {
    //     i64 cur = 0, res = -INF;
    //     for (i64 x: v) {
    //         cur = std::max(x, cur + x);
    //         res = std::max(res, cur);
    //     }
    //     if (res == k) {
    //         std::cout << "Yes\n";
    //         for (i64 i: v) std::cout << i << ' ';
    //         std::cout << endl;
    //     } else {
    //         std::cout << "No\n";
    //     }
    //     return;
    // }
    // if (k < max) {
    //     std::cout << "No\n";
    //     return;
    // }
    // i32 p = std::find(all(s), '0') - s.begin();
    // i64 l = *std::max_element(suf.begin(),std::max(suf.begin(),suf.begin()+p-1));
    // i64 r = *std::max_element(pre.begin()+p,pre.end());
    // std::cout << "Yes\n";
    // bool flag = false;
    // for (i32 i = 0; i < n; i++) {
    //     if (s[i] == '1') {
    //         std::cout << v[i] << ' ';
    //     } else {
    //         std::cout << (flag ? -INF : k - std::max(l,0ll) - std::max(r,0ll)) << ' ';
    //         flag = true;
    //     }
    // }
    // std::cout << endl;
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
