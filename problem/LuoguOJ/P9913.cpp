#define LOCAL
//P9913 「RiOI-03」water problem
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n >= 6) cout << "Yes" << endl;
        else if(n == 3 || n == 2 || n == 5)cout << "No" << endl;
        else cout << "Yes" << endl;
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}