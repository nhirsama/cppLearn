#define LOCAL
//T561025 「FAOI-R5」Lovely 139
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long C(int a,int b){
    if(b>a/2) return C(a,a-b);
    long long ans=1;
    for(int i=b;i<=a;i++){
      ans=(ans*i)%mod;
    }
    return ans;
}
void Func(){
    int l,r;
    scanf("%d %d",&l,&r);
    if(l == 0 && r == 0){
      puts("1");
      return;
      }
    long long ans=C(l+r,r)%mod;
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