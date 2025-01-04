#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    long long n,Max = 0;
    cin>>n;
    Max = n;
    for (long long i = 1 ;i<=n;i++) {
        long long t = i;
        while(t > 1){
            if(t & 1) {
                t = (t << 1) + t +1;
                if(t > Max) Max = t;
            }
            else t >>=1;
            if (t < i)break;
        }
    }
    cout<<Max;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}