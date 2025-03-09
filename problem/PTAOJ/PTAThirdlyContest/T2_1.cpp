#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin>>n;
    vector arr(n+5,vector<char>(n+5));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            char c;
            cin>>c;
            arr[i][j] = c;
        }
    }
    for(int i = n;i;i--){
        if(i%2==0){
            for(int j = 0;j<n+1-i;j++){
                cout<<arr[j+1][i+j];
            }
        }
        else {
            for(int j = n-i;~j;j--){
                cout<<arr[j+1][i+j];
            }
        }
    }
    for(int i = n-1;i;i--){
        if(i%2==0){
            int cnt = 1;
            for(int j = i;j;j--){
                cout<<arr[n+1-j][cnt++];
            }
            //            for(int j = 0;j<i;j++){
            //                cout<<arr[j+2][j+1];
            //            }
        }
        else {
            for(int j = 1;j<=i;j++){
                cout<<arr[n+1-j][i-j+1];
            }
        }
    }
    return 0;
}