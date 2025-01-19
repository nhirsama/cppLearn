//A. Fibonacciness
#include <bits/stdc++.h>
using namespace std;
int arr[6];
void Func(){
    cin>>arr[1]>>arr[2]>>arr[4]>>arr[5];
    int ans = 0;
    for(int i=3;i>0;i--){
        int temp = 0;
        if(i == 1){
            arr[3] = arr[1]+arr[2];
            temp++;
            if(arr[2]+arr[3] == arr[4]) temp++;
            if(arr[3]+arr[4] == arr[5]) temp++;
            ans = max(temp,ans);
        }
        else if(i == 2){
            arr[3] = arr[4]-arr[2];
            temp++;
            if(arr[3]+arr[4] == arr[5]) temp++;
            ans = max(temp,ans);
        }
        else if(i == 3){
            arr[3] = arr[5]-arr[4];
            temp++;
            ans = max(temp,ans);
        }
    }
    cout<<ans<<endl;
}
int main() {
    int T;
    cin >> T;
    while(T--){
        Func();
    }
    return 0;
}