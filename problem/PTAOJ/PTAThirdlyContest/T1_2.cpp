#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n,y;
    cin>>n>>y;
    n--;
    while(n--){
        ll x;
        cin>>x;
        if(x<y){
            cout<<"xiao le"<<endl;
        }
        else{
            cout<<"da le"<<endl;
        }
    }
    return 0;
}