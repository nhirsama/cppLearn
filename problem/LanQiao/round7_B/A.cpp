#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
int main() {
    ll ans = 0,t = 0;
    for (int i = 1; i <= 100; i++) {
        t+=i;
        ans+=t;
    }
    cout << ans << endl;
    return 0;
}
