//  B - 1D Akari
//  AtCoder
#include <bits/stdc++.h>

constexpr std::string OJ_NAME{"AtCoder"};
using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    std::string s;
    std::cin >> s;
    bool f = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            if (f) s[i] = 'o', f = false;
        } else {
            if (s[i] == '#') f = true;
        }
    }
    std::cout << s << endl;
//    if (std::find(s.begin(), s.end(), '#') == s.end()) {
//        s[0] = 'o';
//        std::cout << s << endl;
//        return;
//    }
//    int l = 0, r = s.size();
//    while (l < s.size() && s[l] == '#') l++;
//    while (l < r && s[r - 1] == '#') r--;
//    if (l < r) {
//        for (int i = l; i < r; i++) s[i] = 'o';
//    }
//    if (std::ranges::find(s, '.') == s.end()) {
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] == 'o') {
//                s[i] = '.';
//                break;
//            }
//        }
//    }
//    std::cout << s << endl;

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}