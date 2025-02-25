#include <bits/stdc++.h>
using namespace std;
const int N = 55,mod = 1e9+7;
int kmp[N],n,dp[N][N];
long long ans = 0;
string s;
int main(){
    cin>>n>>s;
    s = "#"+s;
    int m = s.size()-1;
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && s[i] != s[j+1]) j = kmp[j];
        if (s[i] == s[j+1]) j++;
        kmp[i] = j;
    }
    dp[0][0] = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            for(char c = 'a';c<='z';c++){
                int u = j;
                while(u && s[u+1] != c)u = kmp[u];
                if(s[u+1] == c)u++;
                if(u<m)dp[i+1][u] = (dp[i+1][u]+dp[i][j])%mod;
                
            }
        }
    }
    for(int i = 0;i<m;i++){
        ans = (ans+dp[n][i])%mod;
    }
    cout<<ans;
    return 0;
}