#define LOCAL
//P9236 [蓝桥杯 2023 省 A] 异或和之和
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int arr1[65], arr0[65];
int num[100005];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int m = 0;
    int cnt = 0;
    while (n>=(m=m+1)) {
        int j;
        scanf("%d", &j);
        j^=cnt;
        cnt = j;
        // num[m] = num[m-1]^j;
        // j = num[m];
        for (int i = 0; i<23; i++,j>>=1) {
            if (j & 1) {
                arr1[i]++;
            }
            else {
                arr0[i]++;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < 23; i++) {
        //前缀异或和，当从a1到ai的异或和是num[i]^num[0]
        ans += 1ll * arr1[i] * (arr0[i]+1) * (1 << i);
    }
    cout << ans << endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
