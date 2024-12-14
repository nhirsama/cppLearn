//#define LOCAL
//P3370 【模板】字符串哈希
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
string s[10005];
set<string> ss;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        ss.insert(s[i]);
    }
    cout << ss.size() << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}