#define LOCAL
//B3644 【模板】拓扑排序 / 家谱树
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
vector <int> g[105];
int deg[105];
int n;
void add(int x,int y){
    g[x].push_back(y);
    deg[y]++;
}
void topology(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            q.push(i);
            cout<<i<<" ";
        }
    }
    while(!q.empty()){
        int x = q.front();q.pop();
        for(int i : g[x]){
            deg[i]--;
            if(deg[i]==0){
                q.push(i);
                cout<<i<<" ";
            }
        }
    }
    cout<<endl;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;i++){
        int x;
        while(cin>>x){
            if(x == 0) break;
            add(i,x);
        }
    }
    topology();
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}