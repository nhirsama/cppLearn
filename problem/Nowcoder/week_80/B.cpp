#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int arr[N*2];
long long int ans,ans2;
int main() {
    int n;
    cin>>n;
    for(int i = 1;i<=2*n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr+1,arr+2*n+1);
    for(int i = 1;i<2*n;i+=2){
        ans+=arr[i+1]-arr[i];
    }
    for(int i = 2;i<2*n-1;i+=2){
        ans2+=arr[i+1]-arr[i];
    }
    ans2 += arr[2*n]-arr[1];
    cout<<min(ans2,ans);
    return 0;
}
