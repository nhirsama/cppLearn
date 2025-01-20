#define LOCAL
//P1197 [JSOI2008] 星球大战
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
vector<int> g[N];
int a[N], b[N];
bool flag[N];

int find(int x) {
    return x == a[x] ? x : a[x] = find(a[x]);
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) a[i] = i;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        scanf("%d", &b[i]);
        flag[b[i]] = true;
    }
    int ans = n-k;
    for (int i = 0; i < n; i++) {
        if (!flag[i])
            for (int j: g[i]) {
                if (!flag[j]) {
                    if (find(i) != find(j)) {
                        a[find(i)] = find(j);
                        ans--;
                    }
                }
            }
    }
    int anss[k];
    for (int i = k - 1; ~i; i--) {
        flag[b[i]] = false;
        anss[i] = ans;
        ans++;
        for (int j: g[b[i]]) {
            if (!flag[j]) {
                if (find(b[i]) != find(j)) {
                    a[find(b[i])] = find(j);
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < k; i++) {
        cout << anss[i] << "\n";
    }
    cout << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
