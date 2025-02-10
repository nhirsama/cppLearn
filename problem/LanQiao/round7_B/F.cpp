#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[10005];
    int ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(arr[j] != j)  {
                ans++;
                swap(arr[arr[j]],arr[j]);
            }
        }
    }
    cout<<ans;
    return 0;
}