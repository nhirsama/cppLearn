#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int arr[N],n,m;
int main(){
    cin>>n>>m;
    while(m--){
        int a;
        char b;
        cin>>a>>b;
        if (b == 'M') {
            if(arr[a])puts("No");
            else puts("Yes");
            arr[a]++;
        }
        else {
            puts("No");
        }
    }
    return 0;
}