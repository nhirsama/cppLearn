#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main () {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int nn; cin >> nn;
        int ans = 1e9;
        bool check = false;
        int p = nn;
        while(p) {
            if(p % 10 == 7) check = true;
            p /= 10;
        }
        if(check) {
            cout << 0 << "\n";
            continue;
        }
        int d = 9;
        while(d <= 999999999) {
            int n = nn;
            check = false;
            for(int i = 1; i <= 10; i++) {
                n += d;
                int p = n;
                while(p) {
                    if(p % 10 == 7) check = true;
                    p /= 10;
                }
                if(check) {
                    ans = min(ans, i);
                    break;
                }
            }
            d = d * 10 + 9;
        }
        cout << ans << "\n";
    }
}