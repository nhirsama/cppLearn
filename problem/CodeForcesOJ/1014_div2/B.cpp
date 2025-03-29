//B
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
    //000,001,010,011,100,101,110,111
    std::string a, b;
    std::cin >> a >> b;
    i64 cntodd = 0, cnteven = 0;
    for (i32 i = 0; i < n; i++) {
        if (i & 1) {
            if (a[i] == '0') cntodd++;
            if (b[i] == '0') cnteven++;
        } else {
            if (b[i] == '0') cntodd++;
            if (a[i] == '0') cnteven++;
        }
    }
    if (n & 1) {
        if (cntodd >= n / 2 && cnteven > n / 2) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    else {
        if (cntodd >= n / 2 && cnteven >= n / 2) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    // if (cntodd>=n-cntodd && cnteven>=n-cnteven) {
    //     std::cout<<"YES\n";
    // }
    // else {
    //     std::cout<<"NO\n";
    // }
    // for (i32 i = 0; i < n; i++) {
    //     if (i > 0 && (b[i - 1] == '0' && a[i] == '0')) { if (i < n - 1) std::swap(b[i - 1], b[i + 1]); } else if (
    //         i > 0 && (b[i - 1] == '0' && a[i] == '1')) std::swap(b[i - 1], a[i]);
    //     else if (i < n - 1 && (b[i + 1] == '0' && a[i] == '1')) std::swap(b[i + 1], a[i]);
    // }
    // for (auto i: a) {
    //     if (i == '1') {
    //         std::cout << "NO" << endl;
    //         return;
    //     }
    // }
    return;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
