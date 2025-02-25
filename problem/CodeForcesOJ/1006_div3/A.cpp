#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

void Func(){
    int n,k,p;
    cin>>n>>k>>p;
    if(k>=0){
        if(n*p<k)cout<<-1 endl;
        else cout<<k/p+(k%p!=0) endl;
    }
    else {
        if(-n*p>k)cout<<-1 endl;
        else cout<<abs(k)/p+(abs(k)%abs(p)!=0) endl;
    }
}
int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
