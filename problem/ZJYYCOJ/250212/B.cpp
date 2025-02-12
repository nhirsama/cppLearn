#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long int ll;
#define first x;
#define second y;
int rd[N], n, m;
vector<int> g[N];
bool st[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        rd[y]++;
    }
    queue<int> ans;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 1; i <= n; i++) {
        if (rd[i] == 0) {
            pq.push(i);
            st[i] = true;
        }
    }
    while (!pq.empty()) {
        int temp = pq.top();
        pq.pop();
        ans.push(temp);
        for (int v : g[temp]) {
            if (--rd[v] == 0) {
                pq.push(v);
                st[v] = true;
            }
        }
    }
    if (ans.size() == n) {
        while (!ans.empty()) {
            cout << ans.front();
            ans.pop();
            if(!ans.empty()) cout<<' ';
        }
    } else {
        cout << "-1\n";
    }
    return 0;
}
