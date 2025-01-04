//#define LOCAL
//P1097 [NOIP2007 提高组] 统计数字
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
map<int ,int > m;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        m[x]++;
    }
    for(pair<int,int> i:m){
        printf("%d %d\n",i.first,i.second);
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}