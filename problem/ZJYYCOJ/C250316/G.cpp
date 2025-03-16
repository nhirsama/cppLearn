//模板
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// #define x first
// #define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long


signed main() {
    i64 t;
    cin >> t;
    while (t--) {
        i64 n;
        cin >> n;
        vector<i32> a(n), d(n);
        map<i32, i32> mp;
        for (i64 i = 0; i < n; i++) {
            i64 x = 0;
            cin >> a[i] >> d[i];
            i32 aa = 100;
            while (0<(aa = aa-a[i])) x++;
            if (mp.find(x * d[i]) == mp.end()) {
                mp[x * d[i]] = 1;
            } else mp[x * d[i]]++;
        }
        i32 maxx = 0x3f3f3f3f, maxn = 1;
        for (auto [x,y]: mp) {
            if (x < maxx) {
                maxx = x;
                maxn = y;
            }
        }
        printf("%.15f\n", 1 - (double) maxn / (2.0 * n));
    }

    return 0;
}
