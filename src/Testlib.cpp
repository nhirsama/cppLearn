#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    int x, y, idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Point> pts(n);
        for (int i = 0; i < n; i++) {
            cin >> pts[i].x >> pts[i].y;
            pts[i].idx = i + 1;
        }
        // 存放四种候选配对及其距离和
        ll bestSum = -1;
        vector<pair<int, int>> bestPairs;

        // 四个方向的系数
        const vector<pair<int, int>> dirs = {
                {1,  1},
                {1,  -1},
                {-1, 1},
                {-1, -1}
        };

        // 对每一种方向尝试
        for (auto [px, py]: dirs) {
            // 计算投影值并排序
            vector<pair<ll, int>> ord(n);
            for (int i = 0; i < n; i++) {
                ll u = ll(px) * pts[i].x + ll(py) * pts[i].y;
                ord[i] = {u, i};
            }
            sort(ord.begin(), ord.end(),
                 [](auto &a, auto &b) { return a.first < b.first; });

            // 构造配对并计算总距离
            ll curSum = 0;
            vector<pair<int, int>> curPairs;
            curPairs.reserve(n / 2);
            for (int i = 0; i < n / 2; i++) {
                int i1 = ord[i].second;
                int i2 = ord[n - 1 - i].second;
                curPairs.emplace_back(pts[i1].idx, pts[i2].idx);
                curSum += ll(abs(pts[i1].x - pts[i2].x))
                          + ll(abs(pts[i1].y - pts[i2].y));
            }

            if (curSum > bestSum) {
                bestSum = curSum;
                bestPairs = move(curPairs);
            }
        }

        // 输出最优配对
        for (auto &pr: bestPairs) {
            cout << pr.first << " " << pr.second << "\n";
        }
    }

    return 0;
}
