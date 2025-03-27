//B
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

i64 L(i64 x, i64 n) {
    while (n--) {
        if (!x) return 0;
        x >>= 1;
    }
    return x;
}

i64 U(i64 x, i64 n) {
    while (n--) {
        if (x<=1) return x;
        x = (x + 1) >> 1;
    }
    return x;
}

void nhir() {
    i64 x, n, m;
    std::cin >> x >> n >> m;
    std::cout << L(U(x, m), n) << ' ' << U(L(x, n), m) << endl;
    //    i64 y = (x>>std::min(35ll,n+m));
    //    bool flag = false,flag2 = false;
    //    if (n+m<=30) {
    //        i64 t = (x>>n)-(y<<m);
    //        flag = t;
    //        t = (y<<(m+n))-x;
    //        if (t)t++;
    //        flag2 = (t==(t&-t));
    //    }
    //    std::cout<<y+flag2<< ' '<<y+flag<<endl;
    // if (n + m > 30) {
    //     if (n <= 30) {
    //         if (x > (1ll << n) && (x & 1)) {
    //             std::cout << "0 1\n";
    //         } else std::cout << "0 0" << endl;
    //     } else std::cout << "0 0" << endl;
    // } else {
    // n = min(n, 31ll);
    // m = min(m, 31ll);
    // i64 max = x, min = x;
    // for (i32 i = 0, j = 0; i < n || j < m;) {
    //     if (max & 1) {
    //         if (j < m)max = (max + 1) >> 1, j++;
    //         else max >>= 1, i++;
    //     } else {
    //         if (i < n)max = max >> 1, i++;
    //         else max >>= 1, j++;
    //     }
    // }
    // for (i32 i = 0, j = 0; i < n || j < m;) {
    //     if (min & 1) {
    //         if (i < n)min = min >> 1, i++;
    //         else min = ((min + 1) >> 1), j++;
    //     } else {
    //         if (j < m)min = min >> 1, j++;
    //         else min >>= 1, i++;
    //     }
    // }
    // std::cout << min << " " << max << endl;
    //}
}

signed main() {
    ;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
