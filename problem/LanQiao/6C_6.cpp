#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n,Max = 0;
    cin>>n;
    Max = n;
    while(n > 1){
        if(n & 1) {
            //n = n*3 + 1;
            n = (n << 1) + n +1;
            if(n > Max) Max = n;
        }
        else n >>=1;
    }
    cout<<Max;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}