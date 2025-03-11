#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,arr[N],d;
int main(){
    int ans = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i = 1;i<=n;i++){
        if(arr[i]>arr[i-1])ans = arr[i];
        else break;
    }
    cout<<ans;
    return 0;
}