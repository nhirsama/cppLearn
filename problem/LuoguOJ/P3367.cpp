#define LOCAL
//P3367 【模板】并查集
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int n,m,root[N];

int find(int x){
    if(x==root[x]) return x;
    return root[x]=find(root[x]);
}
int main() {
#ifdef LOCAL
    freopen("inAndoutFile/P3367_1.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        root[i]=i;
    }
    while(m--){
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1){
            root[find(x)]=find(y);
        }
        else if(z==2){
            if(find(x)==find(y)) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}