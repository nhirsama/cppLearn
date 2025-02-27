//P1103 书本整理
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' ' <<
typedef pair<int, int> pii;
int dp[N][N],n,k;//最后一本是第i本书时，选j本书后整齐度最小值是多少
pair<int,int> arr[N];
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
         cin>>arr[i].x>>arr[i].y;
    }
    sort(arr+1,arr+n+1);
    memset(dp,0x3f,sizeof dp);
    dp[1][1] = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<min(i,n-k);j++){
            for (int k = 1;k<i;k++) {
                if (j>1)dp[i][j] = min(dp[k][j-1]+abs(arr[i].y-arr[k].y),dp[i][j]);
                else dp[i][j] = 0;
            }
        }
    }
    cout<<dp[n][n-k];
    return 0;
}
