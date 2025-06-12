//  E. Changing the String
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    // std::map<char, std::priority_queue<char, std::vector<char>, std::greater<> > > mp;
    std::array<std::array<std::set<i32>, 3>, 3> aas;
    for (i32 i = 0; i < m; i++) {
        char a, b;
        std::cin >> a >> b;
        if (a == b)continue;
        aas[a - 'a'][b - 'a'].insert(i);
    }
    for (auto &i: s) {
        if (i == 'a') continue;
        if (i == 'b') {
            if (aas[1][0].size()) {
                i = 'a';
                aas[1][0].erase(aas[1][0].begin());
                continue;
            }
            if (aas[1][2].size()) {
                if (aas[2][0].size()) {
                    auto p = *aas[1][2].begin();
                    auto it = aas[2][0].lower_bound(p);
                    if (it != aas[2][0].end()) {
                        aas[1][2].erase(aas[1][2].begin());
                        aas[2][0].erase(it);
                        i = 'a';
                        continue;
                    }
                }
            }
        }
        if (i == 'c') {
            if (aas[2][0].size()) {
                aas[2][0].erase(aas[2][0].begin());
                i = 'a';
                continue;
            }
            if (aas[2][1].size() && aas[1][0].size()) {
                auto p = *aas[2][1].begin();
                auto it = aas[1][0].lower_bound(p);
                if (it != aas[1][0].end()) {
                    aas[1][0].erase(it);
                    aas[2][1].erase(aas[2][1].begin());
                    i = 'a';
                    continue;
                }
            }
            if (aas[2][1].size()) {
                aas[2][1].erase(aas[2][1].begin());
                i = 'b';
                continue;
            }
        }
    }
    // for (auto &i: s) {
    //     if (i == 'a') continue;
    //     else if (i == 'b') {
    //         if (mp['b'].size()) {
    //             if (mp['b'].top() == 'a') {
    //                 mp['b'].pop();
    //                 i = 'a';
    //             } else {
    //                 if (mp['c'].size()) {
    //                     if (mp['c'].top() == 'a') {
    //                         mp['b'].pop();
    //                         mp['c'].pop();
    //                         i = 'a';
    //                     }
    //                 }
    //             }
    //         }
    //     } else if (i == 'c') {
    //         if (mp['c'].size()) {
    //             if (mp['c'].top() == 'a') {
    //                 mp['c'].pop();
    //                 i = 'a';
    //             } else {
    //                 if (mp['b'].size() && mp['b'].top() == 'a') {
    //                     mp['b'].pop();
    //                     mp['c'].pop();
    //                     i = 'a';
    //                 } else {
    //                     mp['c'].pop();
    //                     i = 'b';
    //                 }
    //             }
    //         }
    //     }
    // }
    std::cout << s << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
