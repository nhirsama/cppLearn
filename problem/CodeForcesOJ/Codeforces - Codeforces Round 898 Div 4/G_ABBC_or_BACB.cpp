//  G. ABBC or BACB
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    std::string s;
    std::cin >> s;
    i32 acnt = 0, bcnt = 0;
    i32 amin = 0x3f3f3f3f3f, amincnt = 0;
    for (i32 i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            acnt++;
            amincnt++;
            continue;
        }
        if (s[i] == 'B') {
            bcnt++;
            amin = std::min(amin, amincnt);
            amincnt = 0;
        }
        if (i && s[i] == 'B' && s[i - 1] == 'B') amin = 0;
    }
    amin = std::min(amin, amincnt);
    std::cout << ((s[0] == 'A' && s[s.size() - 1] == 'A') ? acnt - amin : acnt) << endl;
//    std::string ss;
//    for (i32 i = s.size() - 1; ~i; i--) ss.push_back(s[i]);
//    i32 ans = 0;
//    for (i32 i = 0; i < s.size() - 1; i++) {
//        if (s[i] == 'A' && s[i + 1] == 'B') {
//            i32 cnt = 0;
//            ans++;
//            s[i] = 'B';
//            s[i + 1] = 'C';
//            for (i32 j = i - 1; ~j; j--) {
//                if (s[j] == 'A' && s[j + 1] == 'B') {
//                    ans++;
//                    s[j] = 'B';
//                    s[j + 1] = 'C';
//                    continue;
//                }
//                if (s[j] == 'B' && s[j + 1] == 'A') {
//                    ans++;
//                    s[j] = 'C';
//                    s[j + 1] = 'B';
//                    continue;
//                }
//                if (cnt++ > 5)break;
//            }
//        }
//        if (s[i] == 'B' && s[i + 1] == 'A') {
//            ans++;
//            i32 cnt = 0;
//            s[i] = 'C';
//            s[i + 1] = 'B';
//            for (i32 j = i - 1; ~j; j--) {
//                if (s[j] == 'A' && s[j + 1] == 'B') {
//                    ans++;
//                    s[j] = 'B';
//                    s[j + 1] = 'C';
//                    continue;
//                }
//                if (s[j] == 'B' && s[j + 1] == 'A') {
//                    ans++;
//                    s[j] = 'C';
//                    s[j + 1] = 'B';
//                    continue;
//                }
//                if (cnt++ > 5)break;
//            }
//        }
//    }
//    i32 res = ans;
//    s = ss;
//    ans = 0;
//    for (i32 i = 0; i < s.size() - 1; i++) {
//        if (s[i] == 'A' && s[i + 1] == 'B') {
//            i32 cnt = 0;
//            ans++;
//            s[i] = 'B';
//            s[i + 1] = 'C';
//            for (i32 j = i - 1; ~j; j--) {
//                if (s[j] == 'A' && s[j + 1] == 'B') {
//                    ans++;
//                    s[j] = 'B';
//                    s[j + 1] = 'C';
//                    continue;
//                }
//                if (s[j] == 'B' && s[j + 1] == 'A') {
//                    ans++;
//                    s[j] = 'C';
//                    s[j + 1] = 'B';
//                    continue;
//                }
//                if (cnt++ > 5)break;
//            }
//        }
//        if (s[i] == 'B' && s[i + 1] == 'A') {
//            ans++;
//            i32 cnt = 0;
//            s[i] = 'C';
//            s[i + 1] = 'B';
//            for (i32 j = i - 1; ~j; j--) {
//                if (s[j] == 'A' && s[j + 1] == 'B') {
//                    ans++;
//                    s[j] = 'B';
//                    s[j + 1] = 'C';
//                    continue;
//                }
//                if (s[j] == 'B' && s[j + 1] == 'A') {
//                    ans++;
//                    s[j] = 'C';
//                    s[j + 1] = 'B';
//                    continue;
//                }
//                if (cnt++ > 5)break;
//            }
//        }
//    }
//    std::cout << std::max(res, ans) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}