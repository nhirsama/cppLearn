#include <bits/stdc++.h>
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<int> y1, y2;
    std::unordered_set<int> y3;
    //std::set<pii> ss;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        if (y == 0) y1.push_back(x);
        if (y == 1) y2.push_back(x);
        if (y == 2) y3.insert(x);
    }
    std::vector<std::pair<int, int> > ans;
    std::sort(y1.begin(), y1.end());
    std::sort(y2.begin(), y2.end());
    int p1 = std::unique(y1.begin(), y1.end()) - y1.begin();
    int p2 = std::unique(y2.begin(), y2.end()) - y2.begin();
    for (int i = 0; i < p2; i++) {
        for (int j = 0; j < p1; j++) {
            if (y3.find(2 * y2[i] - y1[j]) != y3.end()) {
                ok = true;
                //ss.insert({y2[i], y1[j]});
                ans.push_back({y2[i], y1[j]});
                //printf("[%d, 0] [%d, 1] [%d, 2]\n",y1[j],y2[i],2*y2[i]-y1[j]);
            }
        }
    }
    if (!ok) {
        printf("-1");
    } else {
        std::sort(ans.begin(), ans.end());
        auto p = std::unique(ans.begin(), ans.end()) - ans.begin();
        for (int i = 0; i < p; i++) {
            auto [x,y] = ans[i];
            printf("[%d, 0] [%d, 1] [%d, 2]\n", y, x, 2 * x - y);
        }
        // for (auto [x,y]: ans) {
        //     //auto [x,y] = ans[i];
        //     printf("[%d, 0] [%d, 1] [%d, 2]\n", y, x, 2 * x - y);
        // }
    }
}
