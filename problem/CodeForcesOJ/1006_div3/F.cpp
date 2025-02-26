#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' ' <<
constexpr int mod = 2;
typedef pair<int, int> pii;
int c(int n,int m){
    if (m == 0)return 1;
    long long ans = 1;
    for(int i = n;i>n-m;i--){
        ans*=i;
    }
    for(int i = 2;i<=m;i++){
        ans/=i;
    }
    return ans;
}
int lucas(int a,int b){
    if(b == 0) return 1;
    return ((c(a%2,b%2)*lucas(a/2,b/2)))%2;
}
void Func() {
    int n, k;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
         if(lucas(n-1,i)){
             cout<<k<<' ';
         }
         else {
             cout<<0 << ' ';
         }
    }
    cout<<endl;
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
