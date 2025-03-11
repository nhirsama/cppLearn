#define LOCAL
//A. 盔甲战神小胖肚
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char arr[N][N];
int h,w,ans,dx[] = {-1,1,0,0},dy[] = {0,0,1,-1};
void dfs(int x,int y){

}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> arr[i][j];
        }
    }
    dfs();
    cout << ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}