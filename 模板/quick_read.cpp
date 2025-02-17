#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read() {
    ll ans = 0;
    char c = cin.get();
    while (c < '0' || c > '9') c = cin.get();
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = cin.get();
    return ans;
}