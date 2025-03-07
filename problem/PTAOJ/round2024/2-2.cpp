#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    string s;
    unordered_map<string, int> mp;
    cin >> s;
    cin >> k;

    for (int i = 0; i <= s.size() - k; i++) {
        mp[s.substr(i, k)]++;
    }
    int ans = 0;
    for (const auto &i: mp)ans = max(i.second, ans);
    cout << ans;
}
