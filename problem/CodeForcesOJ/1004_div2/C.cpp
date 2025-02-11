#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
typedef long long ll;
void Func(){
    long long n;
    cin>>n;
    long long temp = n;
    int ans = 7;
    while (temp) {
        if (temp%10 == 7) {
            cout<<0<<endl;
            return;
        }
        temp/=10;
    }
    long long base = 9;
    while (base<=999999999) {
        long long aaa = n;
        for (int i = 1; i <= 8; i++) {
            aaa+=base;
            long long temp = aaa;
            while (temp) {
                if (temp%10 == 7) {
                    ans = min(ans,i);
                }
                temp/=10;
            }
        }
        base *= 10;
        base +=9;
    }
    cout<<ans<<endl;
    return;
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
