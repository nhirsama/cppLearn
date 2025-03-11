#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
#define first x;
#define second y;
ll n;
int arr[N];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++){
        if(arr[i-1]<arr[i]){
            arr[i]--;
        }
        if(arr[i-1]>arr[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
