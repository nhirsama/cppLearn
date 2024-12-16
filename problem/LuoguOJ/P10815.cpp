#define LOCAL
//P10815 【模板】快速读入
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int m;
inline int read(){
    char a = getchar_unlocked();
    int n = 0;
    bool flag = false;
    while(a<'0'||a>'9') {
        if(a=='-') flag = true;
        a = getchar_unlocked();
    }
    while(a >= '0' && a <= '9') {
        n=(n<<3)+(n<<1)+(a^48);
        a=getchar_unlocked();
    }
    return flag?-n:n;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    cin >> n;
    while(n--){
        m+=read();
    }
    cout << m << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}