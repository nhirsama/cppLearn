#define LOCAL
//P1825 [USACO11OPEN] Corn Maze S
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
char arr[400][400];
bool st[400][400];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N,M;
void bfs(int beginX,int beginY){
    deque<pair<int,int> > q;
    q.push_back(make_pair(beginX,beginY));
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop_front();
        for(int i=0;i<4;i++){
            int ix = p.first+dx[i];
            int iy = p.second+dy[i];
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>N>>M;
    int beginX,beginY;
    for(int i =1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%c",&arr[i][j]);
            if(arr[i][j] == '@')beginX = i, beginY = j;
        }
    }
    bfs(beginX,beginY);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}