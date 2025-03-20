//P8669 [蓝桥杯 2018 省 B] 乘积最大
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long
constexpr i32 mod = 1e9 + 9;

i64 getmod(i64 x) {
    if (x >= 0) return x % mod;
    return -((-x) % mod);
}

void nhir() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (i64 &x : a) cin >> x;
    sort(a.begin(), a.end());
    i64 ans = 1;
    if (k&1) {
        ans*=a.back();
        a.pop_back();
        k--;
    }
    k+=2;
    i32 op = 1;
    if (ans<0) op = -1;
    while ((k = k-2)) {
        if (a.front()**(a.begin()+1)*op > a.back()**(a.end()-1)*op) {
            ans*=a.front();
            a.erase(a.begin());
            ans = getmod(ans);
            ans*=a.front();
            a.erase(a.begin());
            ans = getmod(ans);
        }
        else {
            ans*=a.back();
            a.pop_back();
            ans = getmod(ans);
            ans*=a.back();
            a.pop_back();
            ans = getmod(ans);
        }
    }
    // vector<i64> nn, pn;
    // //当非负数个数为0，且k为奇数时答案为负数。
    // for (i32 i = 1; i <= n; ++i) {
    //     i64 q;
    //     cin >> q;
    //     if (q >= 0) pn.push_back(q);
    //     else nn.push_back(q);
    // }
    // sort(pn.begin(), pn.end());
    // sort(nn.begin(), nn.end());
    // i128 one = 1;
    // i64 ans = 1;
    // if (pn.size() == 0 && k & 1) {
    //     while (k--) {
    //         ans *= nn.back();
    //         nn.pop_back();
    //         ans = getmod(ans);
    //     }
    // } else {
    //     while (k--) {
    //         if (k >= 2 && nn.size() >= 2) {
    //             if (pn.back() > nn.back() * *(nn.end() - 1)) {
    //                 ans *= pn.back();
    //                 pn.pop_back();
    //                 ans = getmod(ans);
    //             } else {
    //                 ans *= nn.back();
    //                 nn.pop_back();
    //                 ans *= nn.back();
    //                 nn.pop_back();
    //                 ans = getmod(ans);
    //                 k--;
    //             }
    //         } else {
    //             ans *= pn.back();
    //             pn.pop_back();
    //             ans = getmod(ans);
    //         }
    //     }
    // }
    cout << getmod(ans) << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        cin >> T;
    }

    while (T--) nhir();
    return 0;
}
