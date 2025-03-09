#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
struct node{
    int li,ri,num;
};
bool cmp(node a,node b){
    if(a.li==b.li)return a.num<b.num;
    return a.li<b.li;
}
void solve(){
    int n;
    cin>>n;
    vector<node > v(n+1);
    vector<int> ans(n+1);
    for(int i = 1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        v[i] = {a,b,i};
    }
    sort(v.begin()+1,v.end(),cmp);
    int time = 1;
    for(int i = 1;i<=n;i++){
        if(v[i].li>time) time = v[i].li;
        if(v[i].ri>=time) ans[i] = time++;
        else ans[i] = 0;
    }
    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
int main() {

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}