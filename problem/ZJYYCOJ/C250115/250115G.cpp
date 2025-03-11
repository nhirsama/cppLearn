#define LOCAL
#include <bits/stdc++.h>
using namespace std;
char arr[2005][2005];
int arrx[2005],arry[2005],n,m;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%c",&arr[i][j]);
            if(arr[i][j]=='.'){
                arrx[i]++;arry[j]++;
            }
        }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}