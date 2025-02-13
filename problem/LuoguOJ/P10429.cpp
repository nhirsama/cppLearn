//P10429 [蓝桥杯 2024 省 B] 拔河
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;
ll n,arr[N],ans = LLONG_MAX;
set<ll> s;
multiset<ll> ms;
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin>>n;
    for(int i =1; i<=n; i++) {cin >> arr[i];arr[i]+=arr[i-1];}
    for(int i =1; i<=n; i++) {
        for(int j =i; j<=n; j++) {
            ms.insert(arr[j]-arr[i-1]);
        }
    }
    for(int i =1; i<=n; i++) {
        for(int j =i; j<=n; j++) {
            auto p = ms.find(arr[j]-arr[i-1]);
            ms.erase(p);
        }
        for(int j =1; j<=i; j++) {
            ll num = arr[i]-arr[j-1];
            auto p = ms.lower_bound(num);
            if (p!=ms.end()) {ans = min(ans,*p-num);}
            if (p!=ms.begin()) {--p,ans = min(ans,num-*p);}
        }
    }
    // for(int i =n; i; --i) {
    //     for(int j =i; j<=n; j++) {
    //         ll num = arr[j]-arr[i-1];
    //         auto p = s.lower_bound(num);
    //         if(p!=s.end()) ans = min(ans,abs(*p-num));
    //         if(p!=s.begin()) --p,ans = min(ans,abs(num-*p));
    //         s.insert(num);
    //     }
    // }
    cout << ans << endl;
    return 0;
}
