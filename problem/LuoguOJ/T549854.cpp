#define LOCAL
//T549854 「Cfz Round 5」Mata rainen
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
vector<int> g[N];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    bool flag = true;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        if (g[u].size() >=2) flag = false;
    }
    if (n == m)flag = false;
    if (flag) {
        cout << "Yes" << endl;
        int root = 0,a = 0;
        for (int i = 1; i <= m; i++) {
            if (g[i].size() == 0) {
                root = i;
                break;
            }
            if (g[i].size() == 1) {
                a = i;
            }
        }
        stack<int> s;
        for (int i = 1; i <= n; i++) {
            if (i == root || i == a) continue;
            if (g[i].size() == 0) {
                s.push(i);
            }
            else {
                cout << i <<" "<< root << endl;
                cout << g[i][0] <<" "<< root << endl;
            }
        }
        while (!s.empty()) {
            cout << a <<" "<< s.top() << endl;
            a = s.top();
            s.pop();
        }

    }
    else {
        cout << "No" << endl;
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}