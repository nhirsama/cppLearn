#define LOCAL
//P1894 [USACO4.2] 完美的牛栏The Perfect Stall
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 205;
vector <int>g[N];
int colour[N];
bool visited[N];
int n,m,ans;

bool find(int x){
    for(int i:g[x]){
        if(visited[i]) continue;
        visited[i] = true;
        if(!colour[i] || find(colour[i])) {
            colour[i] = x;
            return true;
        };
    }
    return false;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>m;
    for (int i = 1;i<=n;i++){
        int a;
        scanf("%d",&a);
        while (a--){
            int b;
            scanf("%d",&b);
            g[i].push_back(b);
        }
    }
    for (int i = 1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        if (find(i)) ans++;
    }
    cout<<ans<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}