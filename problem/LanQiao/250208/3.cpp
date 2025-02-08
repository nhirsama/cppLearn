//模板
#include <bits/stdc++.h>
using namespace std;
string s;
int l = 0, r = 0,ans,d,u;
int main() {
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if(s[i] == 'L')l++;
        if(s[i] == 'R')r++;
        if(s[i] == 'U')u++;
        if(s[i] == 'D')d++;
    }
    if ((l+r+u+d)&1) {
        cout<<-1;
        return 0;
    }
    ans+=(abs(l-r)+1)/2;
    ans+=abs(u-d)/2;
    cout<<ans<<endl;
    // ans = min(ans,r-abs(l-r+1)/2+u-abs(u-d));
    // ans = min(ans,l-abs(l-r+1)/2+u-abs(u-d));
    // ans = min(ans,u-abs(l-r+1)/2+u-abs(u-d));
    // ans = min(ans,d-abs(l-r+1)/2+u-abs(u-d));
    return 0;
}
