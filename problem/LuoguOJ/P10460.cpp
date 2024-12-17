#define LOCAL
//P10460 防线
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int arr[200000][3];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
            for (int j = arr[i][0]; j <= arr[i][1]; j+=arr[i][2]) {
                ans ^= j;
            }
        }
        if(ans == 0) cout << "There's no weakness." << endl;
        else {
            int num = 0;
            for (int i = 0; i < n; i++) {
                for (int j = arr[i][0]; j <= arr[i][1]; j+=arr[i][2]) {
                    if(ans == j){
                        num ++;
                    }
                }
            }
            cout << ans << ' ' << num << endl;
        }
        end1:
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}