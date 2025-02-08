//模板
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int arr[N],n,k;
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        arr[i]%=k;
    }
    int aa = 0;
    sort(arr+1,arr+n+1);
    aa = arr[n]-arr[1];
    for(int i = 2;i<=n;i++){
        aa = min(aa, arr[i-1]+k-arr[i]);
    }
    cout<<aa<<endl;
    return 0;
}
