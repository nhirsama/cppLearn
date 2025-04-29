#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // 1) 预处理 dp[i]: s[i..n-1] 中最短的缺失子序列长度
    vector<int> dp(n + 2, 0);
    vector<int> nextPos(k, -1);
    const int INF = n + 5;

    dp[n] = 1;
    // 从后向前计算
    for (int i = n - 1; i >= 0; i--) {
        nextPos[s[i] - 'a'] = i;
        // 检查是否有未出现过的字母
        bool foundMissing = false;
        for (int c = 0; c < k; c++) {
            if (nextPos[c] == -1) {
                dp[i] = 1;
                foundMissing = true;
                break;
            }
        }
        if (!foundMissing) {
            int best = INF;
            for (int c = 0; c < k; c++) {
                int np = nextPos[c];
                // np >= 0 保证安全
                best = min(best, 1 + dp[np + 1]);
            }
            dp[i] = best;
        }
    }

    // 2) 为快速匹配 s 中的子序列，记录每个字母的位置列表
    vector<vector<int> > posList(k);
    for (int i = 0; i < n; i++) {
        posList[s[i] - 'a'].push_back(i);
    }

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int cur = -1; // 当前匹配到的位置
        bool ok = true;
        for (char ch: t) {
            auto &v = posList[ch - 'a'];
            auto it = upper_bound(v.begin(), v.end(), cur);
            if (it == v.end()) {
                // 无法继续匹配
                cout << 0 << "\n";
                ok = false;
                break;
            }
            cur = *it;
        }
        if (ok) {
            // 匹配完全部 t，答案为 dp[cur+1]
            cout << dp[cur + 1] << "\n";
        }
    }

    return 0;
}
