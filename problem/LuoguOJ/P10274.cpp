//P10274 [USACO24OPEN] Logical Moos B
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct node{
    int l,r,v;
};
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q,cnt = 1;
    cin>>n>>q;
    vector<int> arr(n+1);
    vector<node> brr(n+1);
    int res = 1,l = 1,r = 1,op = 0;//op为0时认为上一个操作是或，此时res初始为1.
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;
        if(s=="false"){
            res = 0;
        }
        else if(s == "or"){
            brr[cnt++] = {l,i-1,res};
            res = 1;
            l = i+1;
        }
    }
    brr[cnt++] = {l,n,res};
    while (q--) {
        int a,b;
        string s;
        cin>>s>>a>>b;
        

    }
    return 0;
}
