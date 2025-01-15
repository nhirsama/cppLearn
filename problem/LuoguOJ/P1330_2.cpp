
//P1330 封锁阳光大学
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
vector<int> g[N];
int n,m,colour[N],rNum,bNum,ans;

bool dfs(int i, int j){
    if(colour[i]+j==3){
        return false;
    }
    if(colour[i]) return true;
    colour[i] = j;
    if(j == 1)rNum++;
    else if(j == 2) bNum++;
    for(auto k:g[i]){
        if(!dfs(k,3-j)) return false;
    }
    return true;
}
int main() {
#ifdef LOCAL
    freopen("inAndoutFile/P1330_2.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<n;i++) {
        rNum=bNum=0;
        if (colour[i])continue;
        if (!dfs(i,1)) {
            puts("Impossible");
            return 0;
        }
        ans+=min(rNum,bNum);
    }
    cout<<ans<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}