#define LOCAL
//P3879 [TJOI2010] 阅读理解
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
map< string ,vector<int> > mp;
bool cnt[10010];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            mp[s].push_back(i);
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        memset(cnt, 0, sizeof(cnt));
        for (int a : mp[s]) {
            if (cnt[a]) continue;
            cnt[a] = true;
            cout << a+1 << " ";
        }
        cout << endl;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}