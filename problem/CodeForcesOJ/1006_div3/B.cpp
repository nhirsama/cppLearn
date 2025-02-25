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
    int n;
    long long ans = 0;
    string s;
    cin >> n >> s;
    int a = 0,b = 0;
    for(char c : s){
        if(c == '-'){
            a++;
        }
        else b++;
    }
    if(a<2 || b<1) cout<<0<<endl;
    else {
        cout<<1ll*a/2*(a-a/2)*b<<endl;
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
