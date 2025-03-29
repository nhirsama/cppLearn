#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;
using pii = pair<i32,i32> ;
int main(){
	i64 n;
    cin>>n;
    for(i32 i = 1;i<=n;i++){
        cout<<i*2-1<< ' ';
    }
    for(i32 i = n-1;i;i--){
        cout<<i*2<<" \n"[i==1];
    }
	return 0;
}
