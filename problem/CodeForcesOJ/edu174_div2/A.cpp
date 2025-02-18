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
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i <= n-2; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n-4; i++){
        if(v[i] == 1 && v[i+1] == 0 && v[i+2] == 1) {
          cout<< "NO" endl;
          return;
          }
    }
    cout<<"YES" endl;
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
