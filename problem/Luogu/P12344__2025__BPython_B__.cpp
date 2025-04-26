//  P12344 [蓝桥杯 2025 省 B/Python B 第二场] 破解信息
#include <bits/stdc++.h>

using i64 = long long int;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    std::string s;
    std::cin >> s;
    std::vector<int> cnt(50);
    for (auto i: s) {
        cnt[i - 'a']++;
    }
    int max = 0, c = 0;
    for (int i = 25; ~i; i--) {
        if (cnt[i]) {
            for (int j = 0; j < cnt[i]; j++) {
                std::cout << (char) (i + 'a');
            }
            return;
        }
    }
}

signed main() {
    IOS;
    int T = 1;
    while (T--) nhir();
    return 0;
}
