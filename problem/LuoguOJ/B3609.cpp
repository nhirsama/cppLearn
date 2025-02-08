//B3609 [图论与代数结构 701] 强连通分量
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m,num[N],cnt;
vector<int> g[N],g2[N];
bool st[N];
stack<int> s;
void dfs(int u) {
    st[u] = true;
    for (int v : g[u]) {
        if (!st[v]) {
            dfs(v);
        }
    }
    s.push(u);
}
void dfs2(int u) {
    num[u] = cnt;
    for (int v : g2[u]) {
        if (!num[v]) {
            dfs2(v);
        }
    }
}
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g2[y].push_back(x);
    }
    for(int i=1;i<=n;i++) {
        if(!st[i]) {
            dfs(i);
        }
    }
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (!num[u]) {
            cnt++;
            dfs2(u);
        }
    }
    cout<<cnt<<endl;
    vector<int> ans[cnt+1];
    int aaa[N]{},cnt2 = 0;
    for(int i=1;i<=n;i++) {
        if (aaa[num[i]]) {
            ans[aaa[num[i]]].push_back(i);
        }
        else {
            aaa[num[i]] = ++cnt2;
            ans[aaa[num[i]]].push_back(i);
        }
    }
    for(int i=1;i<=cnt;i++) {
        sort(ans[i].begin(),ans[i].end());
        for(int j:ans[i]) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
