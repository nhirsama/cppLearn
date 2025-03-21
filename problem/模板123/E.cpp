//E
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
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

void LingRhythm() {
    i32 n;
    cin >> n;
    vector<i32> arr(n + 1);
    for (i32 i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] ^= arr[i - 1];
    }
    i64 res = 0;
    for (i32 i = 0; i < 31; i++) {
        i32 cnt0 = 0, cnt1 = 0;
        for (i32 x: arr) {
            if ((x >> i) & 1) {
                cnt1++;
            } else {
                cnt0++;
            }
        }
        res += 1ll * cnt0 * cnt1 * (1ll << i);
    }

    cout << res << endl;
}

signed main() {
    i32 T = 1;
    IOS;

    while (T--) LingRhythm();
    return 0;
}
