#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,t,p,k;
    int ans1=0,ans2=0,ans3=0,ans4=0;
    cin>>n>>t>>p>>k;
    int v[1005][105];
    int ac[1005];
    stack <int> s;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(c) {
            ans1 = a;
        }
        if(c && !v[b][a]) {
            v[b][a] = 1;
            if(!ac[a]) ans4 = a;
            ac[a]++;
            ans2 = a;
            s.push(a);
        }
    }
    while(!s.empty()) {
        if(ac[s.top()]<k)break;
        s.pop();
    }
    if(s.empty()) {
        ans3 = -1;
    }
    else ans3 = s.top();
    cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;
    return 0;
}