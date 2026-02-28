//  C. Specialty String
//  21:08
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    i32 n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<char> ve;
    for (auto c: s) ve.push_back(c);
    for (i32 i = 0; i < n; i++) {
        std::vector<char> v;
        for (i32 j = 0; j < ve.size(); j++) {
            if (v.size() && v.back() == ve[j]) {
                v.pop_back();
            } else {
                v.push_back(ve[j]);
            }
        }
        ve = std::move(v);
    }
    if (!ve.size()) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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