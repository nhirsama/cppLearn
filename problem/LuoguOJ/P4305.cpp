#define LOCAL
//P4305 [JLOI2011] 不重复数字
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
        unordered_set <int> s;
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        for (int i : s){
            cout << i << " ";
        }
        cout << endl;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}