#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;
using pii = pair<i32,i32> ;
i64 gcdd(i64 a,i64 b){
    if(a==0 || b == 0)return max(a,b);
    return gcd(a,b);
}
void nhir(){
    i64  a,b;
    cin>>a>>b;
    i32 cnt = 0;
    while(a && b){
        i64 t = gcd(a,b);
        if(t == 1){
            if(a&1) a--,cnt++;
            else if(b&1) b--,cnt++;
            else a--,cnt++;
        }
        else {
            cnt+=(a/t);
            a/=t;
            cnt+=(b/t);
            b/=t;
        }
    }
    cout<<cnt<<endl;
}
int main(){
	i32 t;
    cin>>t;
    while(t--){
        nhir();
    }
	return 0;
}
