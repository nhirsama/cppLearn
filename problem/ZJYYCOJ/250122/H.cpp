#define LOCAL
//H. 回转寿司
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int m,n;
vector<string> C,D;
int arr[10005];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        C.push_back(s);
    }
    map<string,int> mp;
    map<string,int> mpp;
    for(int i=1;i<=m;i++){
      string s;
      cin>>s;
      mp[s]=0;
      mpp[s]=i;
    }
    mpp["null"]=0;
    mp["null"]=0;
    for(int i=0;i<n;i++){
      if(mp.find(C[i])==mp.end()){
        mp["null"]++;
      }
      else mp[C[i]]++;
    }
    long long ans=0;
    for(int i=0;i<=m;i++){
      scanf("%d",arr+i);
    }
    for(const auto& i: mp){
        ans+=arr[mpp[i.first]]*i.second;
    }
    cout<<ans<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}