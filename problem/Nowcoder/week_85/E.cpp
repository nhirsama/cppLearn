//模板
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
#define ALL(x) (x).begin(), (x).end()
#define int long long

signed main() {
    IOS;
    i64 n;
    cin >> n;
    vector<pii> arr(n + 1);
    i32 cnt = 1;
    unordered_map<i32, i32> ump;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].x >> arr[i].y;
        if (!ump.count(arr[i].x)) {
            ump[arr[i].x] = cnt++;
        }
        if (!ump.count(arr[i].y)) {
            ump[arr[i].y] = cnt++;
        }
        arr[i].x = ump[arr[i].x];
        arr[i].y = ump[arr[i].y];
    }
    vector<i32> st(cnt);
    for (i32 i = 1; i <= n; i++) {
        for (i32 j = arr[i].x; j <= arr[i].y; j++) {
            st[j]++;
            if (st[j] > 2) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    i32 ans = 0;
    vector<i32> ansv;
    sort(1 + ALL(arr));
    i32 a = 0, b = 0,flag = 1;
    for (i32 i = 1; i <= n; i++) {
        if (b < arr[i].x) {
            a = arr[i].x;
            b = arr[i].y;
        } else {
            if (flag&1) {
                ans++;
                ansv.push_back(i);
            }
            flag++;
            b = max(b, arr[i].y);
        }
    }
    cout << ans << endl;
    for (auto i: ansv) {
        cout << i << ' ';
    }
    // sort(all1(arr));
    // i32 a = 0, b = 0;
    // vector<i32> ansv;
    // i32 ans = 0;
    // bool flag = 0;
    // for (int i = 0; i < n; i++) {
    //     if (arr[i].x <= b) {
    //         if (flag) {
    //             ans++;
    //             ansv.push_back(i + 1);
    //             flag = 0;
    //         } else flag = 1;
    //     }
    //     a = max(b, arr[i].x);
    //     b = max(b, arr[i].y);
    //     if (a >= b) {
    //         cout << -1 << endl;
    //         return 0;
    //     }
    // }
    // cout<<ans<<endl;
    // for (auto i : ansv) {
    //     cout<<i<<' ';
    // }
    return 0;
}
