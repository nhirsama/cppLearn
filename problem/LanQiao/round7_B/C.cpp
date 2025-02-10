#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
ll ans;
bool st[10];
void bfs(string s,ll n){
    //if(n>=3){ if (s[1]%s[2])return;}
    if(n >= 9){
        if(s[0]+s[1]/s[2]+(s[3]*100+s[4]*10+s[5])/(s[6]*100+s[7]*10+s[8]) == 10) ans++;
        return;
    }
    for(int i = 0; i <= 9; i++){
        if(st[i]) continue;
        if (n==2 && i == 0) continue;
        st[i] = true;
        bfs(s+(char)i,n+1);
        st[i] = false;
    }
}
int main() {
    bfs("",0);
    cout<<ans<<endl;
    return 0;
}
