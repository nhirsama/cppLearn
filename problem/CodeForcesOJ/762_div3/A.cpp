#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

void Solve() {
    string s;
    cin>>s;
    if (s.size()&1) {
        cout<<"NO"<<endl;
        return;
    }
    int len = s.size()/2;
    for(int i = 0;i<len;i++){
        if(s[i] != s[i+len]) {
            cout<<"NO"<<endl;
            return;
        }

    }
    cout<<"YES"<<endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
