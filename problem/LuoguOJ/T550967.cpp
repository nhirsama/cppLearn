
//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int arr1[4], arr2[4];
    for (int i = 0; i < 4; i++) {
      cin >> arr1[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> arr2[i];
    }
    int ans =0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if(i==j)continue;
            if(arr1[i]<arr1[j] && arr2[i]>arr2[j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}