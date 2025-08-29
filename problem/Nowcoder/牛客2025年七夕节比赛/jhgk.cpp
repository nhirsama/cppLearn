//  结婚改口
//  19:34
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};

void nhir() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int64> dpj(5), dpa(5);
    for (auto i: s) {
        if (i == 'q') {
            dpj[0]++;
            dpa[0]++;
        } else if (i == 'c') {
            dpj[1] += dpj[0];
            dpa[1] += dpa[0];
        } else if (i == 'j') {
            dpj[3] += dpj[2];
            dpj[2] += dpj[1];
        } else if (i == 'a') {
            dpa[2] += dpa[1];
        } else if (i == 'y') {
            dpa[3] += dpa[2];
        }
    }
    if (dpa[3] > dpj[3]) {
        std::cout << "qcay\n";
    } else {
        std::cout << "qcjj\n";
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
