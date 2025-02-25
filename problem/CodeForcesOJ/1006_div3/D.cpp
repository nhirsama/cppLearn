#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2006;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' ' <<
typedef pair<int, int> pii;
int dp[N][N];
void Func(){

    int n;
    cin >> n;
    vector<int> v(n+5);
    for(int i = 1; i <= n; i++){
      cin >> v[i];
    }
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++){

    }
    for(int i = n; i; i--){
        if(v[i]<v[i-1]){
            r = i+1;
            break;
        }
    }
    cout << l << ' ' << r << endl;
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
