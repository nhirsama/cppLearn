
#include <bits/stdc++.h>
using namespace std;
int find(int i, vector<int> &v){
    return v[i] == i ? i : v[i] = find(v[i], v);
      }
void Func(){
    int n,m1,m2,ans = 0;
    cin>>n>>m1>>m2;
    vector<int> root(n+5),rootf(n+5);
    vector<pair<int,int> > f,g;
    for(int i=1;i<=n;i++) root[i]=i,rootf[i]=i;
    for(int i = 1;i<=m1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        f.push_back(make_pair(u,v));
    }
    for(int i=1;i<=m2;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        root[find(u,root)]=find(v,root);
        g.push_back(make_pair(u,v));
    }
    for(int i=0;i<m1;i++){
        if(find(f[i].first,root)!=find(f[i].second,root)){
            ans++;
        }
        else rootf[find(f[i].first,rootf)]=find(f[i].second,rootf);
    }
    for(int i=0;i<m2;i++) {
        if(find(g[i].first,rootf)!=find(g[i].second,rootf)) {
            ans++;
            rootf[find(g[i].first,rootf)]=find(g[i].second,rootf);
        }
    }
    cout<<ans<<endl;
}
int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
