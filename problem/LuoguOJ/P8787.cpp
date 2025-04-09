//P8787 [蓝桥杯 2022 省 B] 砍竹子
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i64 n;
    std::cin >> n;
    std::vector<i64> arr(n);
    for (i64 &i: arr) std::cin >> i;
    i64 cnt = 0;
    while (true) {
        i64 maxlen = 0, maxv = -1;
        i64 templen = 0, tempv = -1;
        i64 l = 0, al = 0;
        for (i32 i = 0; i < n; i++) {
            if (arr[i] == tempv) {
                templen++;
            } else {
                if (maxv < tempv) {
                    maxv = tempv;
                    maxlen = templen;
                    al = l;
                } else if (maxv == tempv) {
                    if (maxlen < templen) al = l;
                }
                tempv = arr[i];
                templen = 1;
                l = i;
            }
        }
        if (maxv < tempv) {
            maxv = tempv;
            maxlen = templen;
            al = l;
        } else if (maxv == tempv) {
            if (maxlen < templen) al = l, maxlen = templen;
        }
        if (maxv == 1) {
            break;
        }
        i64 t = (i64) (std::sqrt((maxv >> 1) + 1));
        for (i32 i = 0; i < maxlen; i++) {
            arr[i + al] = t;
        }
        cnt++;
    }
    std::cout << cnt << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        std::cin >> T;
    }

    while (T--) nhir();
    return 0;
}
