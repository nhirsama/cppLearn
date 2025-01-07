#define LOCAL
//P5905 【模板】全源最短路（Johnson）
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int M = 5e4+10;
int g[M][3],n,m;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
	cin>>n>>m;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d",&g[i][0],&g[i][1],&g[i][2]);
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}