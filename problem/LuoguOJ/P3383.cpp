#define LOCAL
//P3383 【模板】线性筛素数
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
bool arr[100000010];
int p[6000010];
int main() {
#ifdef LOCAL
    clock_t start,end1;
    start = clock();
    freopen("inAndoutFile/P3383_1.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n,q;
    int a = 0;
    cin >> n >> q;
    arr[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!arr[i]) p[++a] = i;
        for(int j = 1;j <= i && i*p[j]<=n; j ++) {
            arr[i*p[j]] = true;
            if (i%p[j] == 0)break;
        }
    }
    for (int i = 1; i <= q; i++) {
        int m;
        scanf("%d",&m);
        printf("%d\n", p[m]);
    }
#ifdef LOCAL
    end1 = clock();
    double time_spent = (double) (end1 - start) / CLOCKS_PER_SEC;
    printf("%.3lf\n", time_spent);
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}