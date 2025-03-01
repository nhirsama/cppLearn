#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
int dp[N];
void Solve() {
    int n;
    cin>>n;
    vector<int> v(n+1);
    int ans = 0x3f3f3f3f;
    for(int i = 1;i<=n;i++){
        cin>>v[i];
        if(dp[v[i]]==0) dp[v[i]] = i;
        else {
            ans = min(ans,i-dp[v[i]]+1);
        }
    }
    if (ans == 0x3f3f3f3f)cout<<-1;
    else cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T;
    T = 1;
    while (T--) {
        Solve();
    }
    return 0;
}
