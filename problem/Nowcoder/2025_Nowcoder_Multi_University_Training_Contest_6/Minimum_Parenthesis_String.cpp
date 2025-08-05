//  Minimum Parenthesis String
//  下午12:03
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};

void nhir() {
    int64 n, m;
    std::cin >> n >> m;
    std::vector<std::array<int, 2>> v(m);
    for (auto &[l, r]: v) std::cin >> l >> r;
    std::ranges::sort(v, [](auto &x, auto &y) {
//        if (x[0] == y[0]) return x[1] < y[1];
        return x[0] > y[0];
    });
//    std::set<std::array<int, 2>> st;
//    for (auto t: v) {
//        auto it = st.lower_bound(t);
//        if (it == st.end()) {
//            st.insert(t);
//        } else {
//            if ((*it)[1] < t[0]) {
//                st.insert(t);
//            } else {
//                auto itt = *it;
//                st.erase(it);
//                st.insert({std::max(itt[0], t[0]), std::min(itt[1], t[1])});
//            }
//        }
//    }
//    for (auto [x, y]: st) {
//        std::cout << x << ' ' << y << endl;
//    }
//    std::cout << std::endl;
    std::string s(2 * n, '-');
    int r = 2 * n + 1, cnt = 0;
    for (auto [x, y]: v) {
        if (y < r) {
            s[x - 1] = '(';
            cnt++;
            r = x;
        }
    }
//    std::cout << s << endl;
    for (auto &c: s) {
        if (c == '(') {
            continue;
        } else if (cnt < n) {
            c = '(';
            cnt++;
        } else {
            c = ')';
        }
    }
//    std::cout << s << endl;
    std::stack<char> st;
    bool f1 = true;
    for (auto c: s) {
        if (c == '(') st.push('(');
        else {
            if (st.empty()) {
                f1 = false;
//                break;
                std::cout << -1 << endl;
                return;
            }
            st.pop();
        }
    }
    if (!st.empty()) {
        f1 = false;
        std::cout << -1 << endl;
        return;
    }
    std::cout << s << endl;


//    std::ranges::sort(v, [](auto &x, auto &y) {
//        if (x[1] == y[1]) return x[0] > y[0];
//        return x[1] < y[1];
//    });
//    std::string s2(2 * n, '-');
//    int r2 = 0, cnt2 = 0;
//    for (auto [x, y]: v) {
//        x--;
//        if (x >= r2) {
//            s2[x] = '(';
//            cnt2++;
//            r2 = x + 1;
//        }
//    }
//    for (auto &c: s2) {
//        if (c == '(') {
//            continue;
//        } else if (cnt2 < n) {
//            c = '(';
//            cnt2++;
//        } else {
//            c = ')';
//        }
//    }
//    bool f2 = true;
//    std::stack<char> st2;
//    for (auto c: s2) {
//        if (c == '(') st2.push('(');
//        else {
//            if (st2.empty()) {
//                f2 = false;
//                break;
////                std::cout << -1 << endl;
////                return;
//            }
//            st2.pop();
//        }
//    }
//    if (!st2.empty()) {
//        f2 = false;
////        std::cout << -1 << endl;
////        return;
//    }
//    if (!(f1 || f2)) {
//        std::cout << -1 << endl;
//        return;
//    }
//    if (!f1) {
//        std::cout << s2 << endl;
//        return;
//    }
//    if (!f2) {
//        std::cout << s << endl;
//        return;
//    } else {
//        std::cout << (s < s2 ? s : s2) << endl;
//    }

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