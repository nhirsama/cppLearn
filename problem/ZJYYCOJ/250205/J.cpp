#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 2e5+10;
vector<int> v[N],r,b;

int ai[N],bi[N];
bool visited[N],flag,rv[N],bv[N];
void bfs(int a,bool q){
    if (flag)return;
    if(q){
        r.push_back(a);
        rv[a]=true;
    }
    else{
        b.push_back(a);
        bv[a]=true;
    }
    visited[a]=true;
    for (auto i:v[a]){
        if (q) {
            if (rv[i]) {
                flag=true;
                return;
            }
        }
        else {
            if (bv[i]) {
                flag=true;
                return;
            }
        }
        if(visited[i])continue;
        bfs(i,!q);
    }
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>ai[i];
    }
    for(int i=1;i<=m;i++) {
        cin>>bi[i];
    }
    for(int i=1;i<=m;i++){
        int x,y;
        x = ai[i];
        y = bi[i];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1;i<=n;i++){
        if(visited[i])continue;
        bfs(i,false);
    }

    if (flag) {
        puts("No");
    }
    else puts("Yes");
    return 0;
}