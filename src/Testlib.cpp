#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> g[N];
vector<int> ans[N];
int n,m,root[N],edge[N];
int find(int x){
    return root[x] == x ? x : root[x] = find(root[x]);
}
int main(){
    string s = "aosdpfanlflahsdgfjaasrg";
    cout<<s.substr(5)<<endl;
    s.erase(5,2);
    cout<<s<<endl;
    return 0;
}