#define LOCAL
//L. 满足的序列
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int n,k;
bool st[10];
int num[10];
bool flag = false;
void dfs(string s,int sum,int j){
    if(sum%k == 0 && s.size()>=n){
        if(flag) {
            cout<<endl;
        }
       for (int i = 0;i<s.size();i++){
           cout<<(int)s[i];
           if(i<s.size()-1) cout<<' ';
       }
        flag = true;
    }
    for(int i=1;i<=num[j];i++){
        //if(st[i]) continue;
        //st[i]=true;
        dfs(s+(char)i,sum+i,j+1);
        //st[i]=false;
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>k;
    for(int i=0;i<n;i++){
      cin>>num[i];
    }
    dfs("",0,0);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}