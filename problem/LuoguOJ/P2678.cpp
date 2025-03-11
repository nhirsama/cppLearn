//P2678 [NOIP 2015 提高组] 跳石头
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '
#define allp1(x) (x).begin() + 1, (x).end()
typedef pair<int, int> pii;
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
//        freopen("Code.out", "w", stdout);
    }
    IOS
    cin.tie(nullptr);
    int l,n,m;
    cin>>l>>n>>m;
    vector<int> arr(n+1);
    for(int i = 1;i<=n;i++) cin>>arr[i];
    arr.push_back(l);
    int rr = arr[n+1],lll = 1;
    auto check = [&](int mid){
        int cnt = 0,j = 0;
        for (int i = 1;i<=n+1;i++) {
            if (arr[i]-j<=mid) cnt++;
            else j = arr[i];
        }
        return cnt<=m;
    };
    while(lll<rr){
        int mid = (1ll*rr+lll)>>1;
        if(check(mid) ) lll = mid+1;
        else rr = mid;
    }
    cout<<rr<<endl;
    return 0;
}
