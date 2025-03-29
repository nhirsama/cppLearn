#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;
using pii = pair<i32,i32> ;
int main(){
	ios::sync_with_stdio(false);
	i32 n;
    cin>>n;
    vector<i32> cnt(35);
    vector<i32 > arr(n+1);
    for(i32 i = 1;i<=n;i++){
        cin>>arr[i];
        for(i32 j = 0;(arr[i]>>j);j++){
            if((arr[i]>>j)&1) cnt[j]++;
            //cout<<(arr[i]>>j)<<endl;
        }
    }
    i32 x = 0;
    for(i32 i = 0;i<=30;i++){
        if(cnt[i]>=n-cnt[i]) x|=(1<<i);
        //cout<<cnt[i]<<endl;
    }
    i64 sum =  0;
    for(i32 i = 1;i<=n;i++){
        sum+=(arr[i]^x);
    }
    cout<<x<<endl;
    cout<<sum<<endl;
	return 0;
}
