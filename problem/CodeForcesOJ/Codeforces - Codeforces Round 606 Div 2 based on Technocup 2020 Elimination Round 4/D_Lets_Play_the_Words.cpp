//  D. Let's Play the Words?
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    std::set<std::string> s;
    std::vector<int> cnt[2][2];
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        cnt[v[i][0] - '0'][v[i].back() - '0'].push_back(i);
        s.insert(v[i]);
    }
    if (cnt[0][1].size() + (int) cnt[1][0].size() == 0 && cnt[0][0].size() && cnt[1][1].size()) {
        std::cout << -1 << endl;
    } else if (std::abs((int) cnt[0][1].size() - (int) cnt[1][0].size()) <= 1) {
        std::cout << 0 << endl << endl;
    } else {
        bool b = cnt[0][1].size() < (int) cnt[1][0].size();
        int res = (cnt[b][!b].size() - cnt[!b][b].size()) / 2;
        std::vector<int> ans;
        for (auto i: cnt[b][!b]) {
            reverse(v[i].begin(), v[i].end());
            if (s.find(v[i]) == s.end()) {
                ans.push_back(i + 1);
                if (ans.size() == res) break;
            }
        }
        if (ans.size() == res) {
            std::cout << res << endl;
            for (auto i: ans) {
                std::cout << i << ' ';
            }
            std::cout << endl;
        } else {
            std::cout << -1 << endl;
        }
    }
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
