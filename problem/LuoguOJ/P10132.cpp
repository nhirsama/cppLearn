#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10,inf = 1e3;
int n,s,v = 1,fr = 1;
pair<int ,int> arr[N];
int cnt[N];
int main(){
    cin>>n>>s;
    for(int i = 1;i<=n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    int ans = 0;
    while(true){
        if(s<=0 || s>n)break;
        if(arr[s].first == 1){
            if(arr[s].second<=v && cnt[s]==0)ans++,cnt[s]++;
        }
        else {
            v+=arr[s].second;
            cnt[s]++;
            fr*=-1;
        }
        if(cnt[s]>=inf)break;
        s += v*fr;
    }
    cout<<ans<<endl;
    return 0;
}