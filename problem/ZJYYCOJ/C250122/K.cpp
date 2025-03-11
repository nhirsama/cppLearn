#define LOCAL
//K. 投票
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int n;

bool sortcmp(pair<string, int> p1, pair<string, int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (m.find(s) == m.end()) {
            m[s] = 1;
        } else {
            m[s]++;
        }
    }
    vector<pair<string, int> > v;
    for (auto i: m)v.push_back(i);
    sort(v.begin(), v.end(), sortcmp);
    int ans = v[0].second;
    for (auto i: v) {
        if (i.second == ans) {
            cout << i.first << endl;
        }
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
