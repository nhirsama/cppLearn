#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
#define first x;
#define second y;
ll arr[10],sum,n,x;

int main() {
    cin>>n>>x;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++){
        if(arr[i]<=x) sum+=arr[i];
    }
    cout<<sum<<endl;
    return 0;
}
