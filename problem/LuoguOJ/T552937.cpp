#define LOCAL
//T552937 「FAOI-R5」becoder
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const  int N = 1e5+10;
int n,ti[N],mi[N],L,R;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>L>>R;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&ti[i],&mi[i]);
    }
    for(int i=1;i<=n;i++){
        int t,m;
        scanf("%d%d",&t,&m);
        if(i>=L && i<=R){
            puts("System Error");
        }
        else if(mi[i]>m) puts("Memory Limit Exceeded");
        else if(ti[i]/2>t) puts("Time Limit Exceeded");
        else puts("Accepted");
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}