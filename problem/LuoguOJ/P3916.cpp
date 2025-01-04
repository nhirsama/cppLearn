#define LOCAL
//P3916 图的遍历
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int e[N],ne[N],h[N],idx;
void add(int x,int y){
    e[++idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        add(x,y);
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}