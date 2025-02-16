#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5+10;
typedef long long ll;
void Func(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="0"+s;
    int ans = 0;
    for(int i=0;i<=n;i++){
        if(s[i] == '1' && s[i+1] == '0'){
            ans++;
            i++;
        }
        if(s[i] == '0' && s[i+1] == '1'){
            ans++;
        }
    }
    cout<<ans<<endl;
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
