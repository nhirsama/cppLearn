#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int arr[N],n,q;
map<int,vector<int> > m;
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        m[a].push_back(i);
    }
    for(int i=1;i<=q;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(m[a].size()<b)puts("-1");
        else cout<<m[a][b-1]<<endl;
    }
    return 0;
}