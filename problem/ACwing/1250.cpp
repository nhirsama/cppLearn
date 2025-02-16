#include <bits/stdc++.h>
using namespace std;
const int N = 40005;
int ccb[N];
int find(int x) {
    return ccb[x] == x ? x : ccb[x] = find(ccb[x]);
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i =1;i<=n*n+n;i++)ccb[i] = i;
    for(int i = 1;i<=m;i++){
        int a,b;
        char c;
        cin>>a>>b>>c;
        //a--,b--;
        if(c == 'D') {
            if(find(a*n+b) == find(a*n+b+n)){
                cout<<i<<endl;
                return 0;
            }
            ccb[find(a*n+b)] = find(a*n+b+n);
        }
        else {
            if(find(a*n+b) == find(a*n+b+1)){
                cout<<i<<endl;
                return 0;
            }
            ccb[find(a*n+b)] = find(a*n+b+1);
        }
    }
    cout<<"draw\n";
}