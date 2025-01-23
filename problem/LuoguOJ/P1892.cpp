#define LOCAL
//P1892 [BOI2003] 团伙
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int root[1005];

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
}

int n, m;
vector<int> v[1005];

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) root[i] = i;
    int ans = n;
    for (int i = 0; i < m; i++) {
        char a;
        int x, y;
        cin >> a >> x >> y;
        if (a == 'F') {
            if (find(x) != find(y)) {
                root[find(x)] = find(y);
                ans--;
            }
        } else {
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (v[i].size() > 0) {
            for (int j: v[i]) {
                for (int k: v[j]) {
                    if (find(k) != find(i)) {
                        root[find(k)] = find(i);
                        ans--;
                    }
                }
            }
        }
    }
    cout << ans;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
