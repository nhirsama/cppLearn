#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int ccb[N];

int find(int x) {
    return ccb[x] == x ? x : ccb[x] = find(ccb[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        unordered_map<int, int> ump;
        vector<pair<int, int> > v;
        int n, count = 0;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++)ccb[i] = i;
        for (int i = 1; i <= n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            if (ump.find(a) == ump.end()) ump[a] = ++count;
            if (ump.find(b) == ump.end()) ump[b] = ++count;
            if (c) {
                ccb[find(ump[a])] = find(ump[b]);
            } else {
                v.emplace_back(ump[a], ump[b]);
            }
        }
        bool flag = true;
        for (auto i: v) {
            if (find(i.first) == find(i.second)) {
                flag = false;
                break;
            }
        }
        if (flag)cout << "YES\n";
        else cout << "NO\n";
    }
}
