#include<bits/stdc++.h>
using namespace std;
#define pp ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
vector<int>a[100001];
int s[100001], n;
void solve(){
    pp;
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    sort(s,s+n);
    for(int i=0;i<n;i++){
        for(int j=1;j<=sqrt(s[i]);j++){
            if(s[i]%j==0){
                a[j].push_back(s[i]);
                //需要在满足是因子的基础上判断是否是乘方因子，放在外面是错的
                if(s[i]/j!=j)a[s[i]/j].push_back(s[i]);
            }
        }
    }
    for(int i=100001-1;i>=0;i--){
        if(a[i].size()>=3){
            cout<<a[i][0];
            for(int j=1;j<3;j++)cout<<" "<<a[i][j];
            break;
        }
    }
    return ;
}
int main( ){
    solve();
    return 0;
}