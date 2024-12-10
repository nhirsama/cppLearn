#define LOCAL
//P3904 三只小猪
//记得把文件重定向注释掉
/*
#include <bits/stdc++.h>
using namespace std;
char dp[55][55][100];
void add(int addNum1x,int addNum1y,int addNum2x,int addNum2y,int retNumx,int retNumy){
    for (int i = 1;i<=dp[addNum1x][addNum1y][0];i++){
        dp[retNumx][retNumy][i]=dp[addNum1x][addNum1y][i]+dp[addNum2x][addNum2y][i];
        dp[retNumx][retNumy][0]++;
        if(dp[retNumx][retNumy][i]>=10) {
            dp[retNumx][retNumy][i+1]++;
            dp[retNumx][retNumy][i] -= 10;
        }
    }
    if (dp[retNumx][retNumy][dp[retNumx][retNumy][0]+1]!=0)dp[retNumx][retNumy][0]++;
}
void mul(int x1,int y1,int x2,int y2,int rx,int ry){
    if(dp[x1][y1][0] < dp[x2][y2][0]){
        mul(x2,y2,x1,y1,rx,ry);
        return;
    }
    for (int i = 1;i<=dp[x1][y1][0];i++){
        for (int j = 1;j<=dp[x2][y2][0];j++){
            dp[rx][ry][i+j] = dp[rx][ry][i]*dp[rx][ry][j];
            dp[rx][ry][i+j+1] = dp[rx][ry][i+j]/10;
            dp[rx][ry][i+j]%=10;
        }
    }
    for (int i = dp[x1][y1][0]+dp[x2][y2][0]+1;i>0 && !dp[rx][ry][i];i--){
        dp[rx][ry][0]--;
    }
}
void mul(int x1,int y1,int m,int rx,int ry){
    char a[100];
    for (int i = 1;m;i++){
        a[i]=m%10;
        m=m/10;
        a[0]++;
    }
    for (int i = 1;i<=dp[x1][y1][0];i++){
        for (int j = 1;j<=a[0];j++){
            dp[rx][ry][i+j] = dp[rx][ry][i]*dp[rx][ry][j];
            dp[rx][ry][i+j+1] = dp[rx][ry][i+j]/10;
            dp[rx][ry][i+j]%=10;
        }
    }
    for (int i = dp[x1][y1][0]+a[0]+1;i>0 && !dp[rx][ry][i];i--){
        dp[rx][ry][0]--;
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    if(m>n) {
        cout << 0 << endl;
        return 0;
    }
    if(m==n){
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1;i<=m;i++){
        for (int j = 1;j<=n;j++){
            if(i==j){
                if(i>10){
                    dp[i][j][0] = 2;
                    dp[i][j][1] = i%10;
                    dp[i][j][2] = i/10;
                }
                else {
                    dp[i][j][0] = 1;
                    dp[i][j][1] = i;
                }
            }

        }
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
*/