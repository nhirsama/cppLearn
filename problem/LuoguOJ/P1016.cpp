//P1016 [NOIP 1999 提高组] 旅行家的预算
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 10;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<
typedef pair<int, int> pii;
double D1,C,D2,pi[N],di[N],P,ans = 0;
int n;

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin>>D1>>C>>D2>>P>>n;
    di[0] = 0,pi[0] = P,pi[n+1] = D1;
    for(int i  = 1;i<=n;i++)  cin>>di[i]>>pi[i];
    for(int i = 0;i<=n+1;i++){
        for(int j = 0;j<=n;j++){

        }
    }
    return 0;
}
