#include <bits/stdc++.h>
using namespace std;
const int N = 1005,M = 105;
int dp[M];
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > v(m+5);
    for(int i = 1;i<=m;i++){
        cin>>v[i].first>>v[i].second;
    }
    for(int i = 1;i<=m;i++)
        for(int j = n;j>=v[i].first;j--)dp[j] = max(dp[j],dp[j-v[i].first]+v[i].second);
    cout<<dp[n];
}