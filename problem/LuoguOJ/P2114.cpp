#define LOCAL
//P2114 [NOI2014] 起床困难综合症
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("inAndoutFile/P2114_2.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n,m,ans = 0,c,aa=0,bb=-1;
    char s[5];
    scanf("%d%d",&n,&m);

    for(int i = 0;i<n;i++) {
        cin>>s>>c;
        switch (s[0]) {
            case 'A':aa&=c;bb&=c;break;
            case 'O':aa|=c;bb|=c;break;
            case 'X':aa^=c;bb^=c;break;
            default: break;
        }
    }
    int m2 = m;
    for(int i=29;i>=0;i--){
        int a0 = (aa>>i)&1;
        int b1 = (bb>>i)&1;
        if(a0) ans+=1<<i;
        else if(b1&&(1<<i)<=m) {
            ans+=1<<i, m-=1<<i;
        }
    }
    cout << ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}