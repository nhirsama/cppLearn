//P11449 [USACO24DEC] Roundabount Rounding B
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long long m;
        cin >> m;
        long long ans = 0;
        long long baselow = 5,baseup = 9;
        long long aa = 1,cnt = 10;
        while (aa<m) {
            aa = m%cnt;
            if(m>=baselow) {
                ans+=min(m,baseup)-baselow+1;
            }
            baselow+=4*cnt;
            if (baseup == 9) {
                baseup = 49;
            }
            else baseup = baseup*10+9;
            cnt*=10;
        }
        cout << max(ans-5,0ll) << endl;
    }
    return 0;
}