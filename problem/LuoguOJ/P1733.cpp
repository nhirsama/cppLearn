//#define LOCAL
//P1733 猜数（IO交互版）
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int l = 1,r = 1e9;
    while (l < r) {
        int mid = r+l>>1;
        cout << mid << endl;
        int t;
        cin >> t;
        if (t == -1) l = mid+1;
        else if (t == 0 ) {
            l = mid;
            return 0;
        }
        else r = mid;
    }
    cout << l << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}