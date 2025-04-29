//  A. Vadim's Collection
#include <bits/stdc++.h>

using i64 = long long int;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    std::string s;
    std::cin >> s;
    std::multiset<char> ms(s.begin(), s.end());
    std::string ans;
    for (int i = 0; i < 10; i++) {
        auto it = ms.lower_bound(char('0' + (9 - i)));
        ans.push_back(*it);
        ms.erase(it);
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}