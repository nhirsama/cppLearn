//E. Graph Composition
//wa第二个点，不知道为什么
#include <bits/stdc++.h>
using namespace std;

void Func() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<set<int> > F(n + 1), G(n + 1);
    for (int i = 1; i <= m1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        F[x].insert(y);
        F[y].insert(x);
    }
    int ans = 0;
    for (int i = 1; i <= m2; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].insert(y);
        G[y].insert(x);
    }
    for (int i = 0; i <= n; i++) {
        for (auto j: G[i]) {
            if (F[i].find(j) == F[i].end()) {
                ans++;
                F[i].insert(j);
                F[j].insert(i);
            }
        }
        while (F[i] != G[i]) {
            for (auto j: F[i]) {
                if (G[i].find(j) == G[i].end()) {
                    ans++;
                    F[i].erase(j);
                    F[j].erase(i);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
