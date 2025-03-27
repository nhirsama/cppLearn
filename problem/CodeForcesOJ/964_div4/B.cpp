#include <bits/stdc++.h>
using namespace std;

int f(int a, int b) {
    if (a > b) return 1;
    if (a == b) return 0;
    return -1;
}

void Func() {
    int a[5];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    int ans = 0;
    if (f(a[0], a[2]) + f(a[1], a[3]) > 0) ans++;
    if (f(a[0], a[3]) + f(a[1], a[2]) > 0) ans++;
    if (f(a[0], a[2]) + f(a[1], a[3]) > 0) ans++;
    if (f(a[0], a[3]) + f(a[1], a[2]) > 0) ans++;
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
