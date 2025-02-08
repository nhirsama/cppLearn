
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
void Func(){

    int n,s,m;
    cin>>n>>s>>m;
    vector<pair<int, int> > v(n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&v[i].first,&v[i].second);
    }
    sort(v.begin(),v.begin()+n);
    for(int i=0;i<n;i++){
        if(i == 0 && v[i].first>=s) {
          puts("Yes");
          return;
          }
        if(i == n-1 && m-v[n-1].second>=s) {
          puts("Yes");
          return;
        }
        if(i)if(v[i].first-v[i-1].second>=s) {
            puts("Yes");
            return;
        }
    }
    puts("No");
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
