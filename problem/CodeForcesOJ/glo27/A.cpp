#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

void Func(){
    long long n,m,r,c;
    cin>>n>>m>>r>>c;
    long long i = (r-1)*m+c;
    cout<<(n*m-i)+(m-1)*(n-r)<<endl;
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
