#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
int main() {
    for (int i = 1; i <= 100; i++) {
        for (int j = i; j <= 100; j++) {
            if(-i*i+i+j*j+j == 236*2) cout << i << " " << j << endl;
        }
    }
    int ans = 0;
    for (int i = 26; i <= 33; i++) {
        ans+=i;
    }
cout << ans << endl;
    return 0;
}
