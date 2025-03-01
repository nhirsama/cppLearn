#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, g, k, cnt = 0;
    cin >> n >> g >> k;
    vector<pair<int, string> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].second >> v[i].first;
        if (v[i].first >= 60 && v[i].first < g)cnt += 20;
        else if (v[i].first >= g)cnt += 50;
    }
    auto cmp = [](auto a, auto b) -> auto {
        if (a.first == b.first)return a.second < b.second;
        return a.first > b.first;
    };
    cout << cnt << endl;
    sort(v.begin() + 1, v.begin() + n + 1, cmp);
    for (int i = 1, j = 1; i <= k || j <= k; i++) {
        if (v[i].first < v[i - 1].first)j = i;
        if (j > k)break;
        cout << j << ' ';
        cout << v[i].second << ' ' << v[i].first << endl;
    }
}
