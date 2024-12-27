#define LOCAL
//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int t = 0,n = 0;
    for (int i = 1;i <= 100; i++) {
        t+=i;
        n+=t;
    }
    cout << n << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}