#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int m;
    cin >> m;
    vector<string> w(m);
    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }
    for (int j = 0;j<n;j++) {
        const string& str = v[j];
        bool flag = false;
        for (int i = 0;i<str.size();i++) {
            for (const auto& aa:w) {
                string s = str.substr(i,aa.size());
                if (s == aa) flag = true;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}