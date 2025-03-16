#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    long long ans = 0;
    int cnt = 0;
    long long jnum = 0,ksum = 0;
    for(char i :s){
        if(i == 'J')jnum++;
        else ksum++;
    }
    for (char i : s) {
        if (i == 'J') {
            if (cnt >= 1) {
                ans += 2 * b;
            } else {
                if ((jnum-1)*2*b>jnum*a || (a*2<b && cnt<3 && ksum>cnt)) {
                    cnt = min(cnt + 1, 3);
                } else {
                    ans += a;
                }
            }
            jnum--;
        } else {
            if ((cnt > jnum) || cnt>1) {
                ans += b;
                cnt--;
            } else {
                ans += a;
            }
            ksum--;
        }
        
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}