#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    priority_queue<long long> p;
    for(int i = 1;i<=n*n;i++){
        long long x;
        cin>>x;
        p.push(x);
    }
    long long ans = 0;
    for(int i = 1;i<=3;i++){
        ans+=p.top();
        p.pop();
    }
    if(ans>=n/2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}