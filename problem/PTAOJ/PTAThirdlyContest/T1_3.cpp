#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    string name;
    int a,b,c;
    int get(){
        return a*4+b*3+c*3;
    }
};
int main() {
    ll n;
    cin>>n;
    vector<node> arr(n+10);
    for(int i = 1;i<=n;i++){
        cin>>arr[i].name>>arr[i].a>>arr[i].b>>arr[i].c;
    }
    sort(arr.begin()+1,arr.begin()+n+1,[](node a,node b){
        ll aa = a.a*4+a.b*3+a.c*3;
        ll bb = b.a*4+b.b*3+b.c*3;
        if(aa==bb) return a.name<b.name;
        return aa>bb;
    });
    for(int i = 1;i<=n;i++){
        cout<<arr[i].get()<<' '<<arr[i].name<<endl;
        //cout<<arr[i].name<<' '<<arr[i].a<<' '<<arr[i].b<<' '<<arr[i].c<<endl;
    }
    return 0;
}