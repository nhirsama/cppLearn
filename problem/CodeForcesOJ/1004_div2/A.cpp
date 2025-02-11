#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
typedef long long ll;
void Func(){
    int a,b;
    cin>>a>>b;
    if(b == a+1) puts("Yes");
    else if((a+1-b) >= 9 && (a+1-b)%9 == 0) puts("Yes");
    else puts("No");
}
int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
