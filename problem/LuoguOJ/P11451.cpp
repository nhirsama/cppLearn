//P11451 [USACO24DEC] It's Mooin' Time B
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n, k;
    cin >> n >> k;
    cin >> s;
    set<string> ans;
    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            if (i == j)continue;
            int cnt = 0;
            vector<bool> st(n, false);
            for (int m = 0; m < n - 2; m++) {
                if ((s[m] == i && s[m + 1] == j && s[m + 2] == j)) {
                    cnt++;
                    st[m] = true;
                    st[m + 1] = true;
                    st[m + 2] = true;
                    m += 2;
                }
            }
            for (int m = 0; m < n - 2; m++) {
                if (st[m] || st[m + 1] || st[m + 2]) continue;
                if ((s[m] == i && s[m + 1] == j) ||
                    (s[m] == i && s[m + 2] == j) ||
                    (s[m + 1] == j && s[m + 2] == j)) {
                    cnt++;
                    break;
                }
            }
            if (cnt >= k) {
                string t;
                t.push_back(i);
                t.push_back(j);
                t.push_back(j);
                ans.insert(t);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto i: ans) {
        cout << i << '\n';
    }
    return 0;
}
