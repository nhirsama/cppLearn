//D
#include <bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long int i64;
typedef int i32;
typedef short i16;
typedef char i8;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

void nhir() {
    i64 n;
    cin >> n;
    i64 x = 1, y = 1;
    auto gex = [&n](i128 y) {
        i128 xma = 1 << 120, xmi = y;
        i128 y3 = y * y * y;
        while (xma > xmi) {
            i128 mid = (xma + xmi) / 2;
            if (mid * mid * mid >= y3 + n) xma = mid;
            else xmi = mid + 1;
        }
        return xmi;
    };
    for (; 3 * y * y + 3 * y + 1 <= n; y++) {
        while (x * x * x - y * y * y < n) x++;
        if (x * x * x - y * y * y == n) {
            cout << x << ' ' << y << endl;
            return;
        }
    }
    cout << -1 << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
