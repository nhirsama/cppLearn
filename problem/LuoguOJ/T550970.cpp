#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,p;
    cin >> n >> p;
    int ans = 0;
    int v[1005]{0};
    for (int i = 0; i < n; i++) {
        int m,q;
        cin >> m>>q;
        if(!(v[m]) && q) {
            ans++;
            v[m] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}