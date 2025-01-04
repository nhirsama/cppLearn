#define LOCAL
//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 90010;
char arr[305][305];
int ne[N*8],h[N*8],e[N*8],idx,w[N*8];
int n,m,dx[] = {-1,0,0,1},dy[] = {0,-1,1,0};
bool visited[N];
void addEdge(int x,int y,int z) {
    e[++idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
    w[idx] = z;
}
int spfa(int a,int b){
    int dist[N];
    memset(dist,0x3f,sizeof dist);
    dist[a]=0;
    queue<int> q;
    q.push(a);
    visited[a] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        visited[t] = false;
        for (int j = h[t] ; e[j] || j;j = ne[j]) {
            if (dist[e[j]] > dist[t] + w[j]) {
                dist[e[j]] = dist[t] + w[j];
                if (!visited[e[j]]) {
                    q.push(e[j]);
                }
            }
        }
    }
    if (dist[b] == 0x3f3f3f) return -1;
    return dist[b];
}
int main() {
#ifdef LOCAL
    freopen("inAndoutFile/P1825_2.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%s",arr[i]);
    }
    vector<int> v[27];
    //获取起止点以及传送点。
    int be,en;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (arr[i][j] == '#') continue;
            if (arr[i][j] == '=') en = i*m+j+1;
            if (arr[i][j] == '@') be = i*m+j+1;
            if ('A' <= arr[i][j] && arr[i][j] <= 'Z') {
                v[arr[i][j]-'A'].push_back(i*m+j+1);
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (arr[i][j] == '#') continue;
            for (int k=0;k<4;k++) {
                int x = i + dx[k],y = j + dy[k];
                if (x<0 || y < 0 || x >= n || y >= m) continue;
                if (arr[x][y] == '#') continue;
                if ('A' <= arr[x][y] && arr[x][y] <= 'Z') {
                    if (v[arr[x][y]-'A'].size() == 2) {
                        if (v[arr[x][y]-'A'][0] == x*m+y+1) addEdge(i*m+j+1,v[arr[x][y]-'A'][1],1);
                        else addEdge(i*m+j+1,v[arr[x][y]-'A'][0],1);
                    }
                }
                else addEdge(i*m+(j+1),x*m+(y+1),1);
                //addEdge(x*m+(y+1),i*m+(j+1),1);
            }
        }
    }
    int t = spfa(be,en);
    cout<<t<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}