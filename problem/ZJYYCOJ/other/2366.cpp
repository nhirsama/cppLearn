#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int A[N];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i = 0;i<k;i++){
        int a;
        scanf("%d",&a);
        A[a]++;
    }
    int ans=0;
    int r  = N-1;
    while(n){
        for(int j = 0;j<=1;j++){
            while ((A[r] == 0 || A[r]>n)&&r>0)r--;
            if(j == 0){
                ans+=A[r];
                n-=A[r];
            }
            else n-=A[r];
            r--;
        }
    }
    cout << ans << endl;
    return 0;
}