#define LOCAL
//P1551 亲戚
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int arr[5005];

int find(int x) {
    return x == arr[x] ? x : find(arr[x]);
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)arr[i] = i;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        arr[find(x)] = find(y);
    }
    for (int i = 1; i <= p; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (find(x) == find(y)) puts("Yes");
        else puts("No");
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
