#define LOCAL
//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int a,b,c,d,x;
    cin>>a>>b>>c>>d>>x;
   if(x<a && x<c) cout<<0<<endl;
   else if(x>=a && x<c) cout<<b<<endl;
   else if(x>=a && x>=c) cout<<b+d<<endl;
   else if(x<a && x>=c) cout<<d<<endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}