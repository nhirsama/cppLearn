#define LOCAL
//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int n,m,ans,x,a1=0,a2=-1;
char str[5];
int main() {
#ifdef LOCAL
    freopen("inAndoutFile/P2114_2.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    while(n--){
        scanf("%s%d",str,&x);
        if(str[0]=='A') a1&=x, a2&=x;
        if(str[0]=='X') a1^=x, a2^=x;
        if(str[0]=='O') a1|=x, a2|=x;
    }
    for(int j=29;~j;--j){
        if(a1>>j&1) ans+=1<<j;
        else if(a2>>j&1&&(1<<j)<=m) ans+=1<<j, m-=1<<j;
    } printf("%d",ans);
    return 0;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}