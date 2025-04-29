//  C. Sports Betting
#include <bits/stdc++.h>

using i64 = long long int;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i:a) std::cin>>i;
    std::map<int,int> cnt;
    for (int x: a) cnt[x + 1]++;
    for (auto [d, c]: cnt) {
        if (c >= 4) {
            std::cout << "Yes\n";
            return;
        }
    }
    std::vector<std::pair<int, int> > v(all(cnt));
    int m = v.size();
    int i = 0;
    while (i < m) {
        if (v[i].second < 1) {
            i++;
            continue;
        }
        int ge2 = (v[i].second >= 2 ? 1 : 0);
        int j = i + 1;
        while (j < m && v[j].first == v[j - 1].first + 1 && v[j].second >= 1) {
            if (v[j].second >= 2) ge2++;
            j++;
        }
        if (ge2 >= 2) {
            std::cout << "Yes\n";
            return;
        }
        i = j;
    }
    std::cout << "No\n";
}

signed main() {
    IOS;
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}