#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long n,arr[N],brr[N],ans = 0;
int main()
{
    // 请在此输入您的代码
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 1;i<=n;i++)cin>>brr[i];
    long long len = 1;
    for(int i = 2;i<=n;i++){
        if(arr[i]+min(brr[i],brr[i-1])>arr[i-1]+max(brr[i],brr[i-1])){
            len++;
        }
        else {
            ans+=len*(len-1)/2;
            len = 1;
        }
    }
    ans+=len*(len-1)/2;
    cout<<ans<<endl;
    return 0;
}