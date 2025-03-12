//模板
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef pair<int, int> pii;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    int ans = 0;
    for (int i = 0;i<=63;i++) {
        if ((1ll<<i)&n) ans = max(ans,i);
    }
    cout<<ans<<endl;
    return 0;
}
