//P10189 [USACO24FEB] Maximizing Productivity B
#include<bits/stdc++.h>
using namespace std;

struct node {
    int v, s, n;
};

int main() {
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> xf(1e6 + 1), ti(n + 1), ci(n + 1);
    vector<bool> ans(q);
    for (int i = 1; i <= n; i++) {
        cin >> ci[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> ti[i];
        if (ci[i] - ti[i] > 0)xf[0]++, xf[ci[i] - ti[i]]--;
    }
    vector<node> qu(q);
    for (int i = 0; i < q; i++) {
        cin >> qu[i].v >> qu[i].s;
        qu[i].n = i;
    }
    sort(qu.begin(), qu.end(), [](node a, node b)-> bool {
        if (a.s == b.s)return a.v < b.v;
        return a.s < b.s;
    });
    int sum = xf[0], ptr = 1;
    for (auto i: qu) {
        for (; ptr <= i.s; ptr++)sum += xf[ptr];
        if (sum >= i.v) ans[i.n] = true;
        else ans[i.n] = false;
    }
    for (int i = 0; i < q; i++) {
        if (ans[i])cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
