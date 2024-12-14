//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int q;
    cin >> q;
    while (q--) {
        string a,b,c;
        cin >> a >> b >> c;
        c = c.substr(0,c.size()-1);
        if (a != "eat")cout<<a<<endl;
        else if (a == "eat" && c != "eat")cout<<c<<endl;
        else cout<<b<<endl;
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}