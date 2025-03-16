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
#define all1(x) (x).begin(), (x).end()
#define int long long

signed main() {
    IOS;
    i64 n;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)cin >> arr[i].x >> arr[i].y;
    sort(all1(arr));
    i32 a = 0, b = 0;
    vector<i32> ansv;
    i32 ans = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].x <= b) {
            if (flag) {
                ans++;
                ansv.push_back(i + 1);
                flag = 0;
            } else flag = 1;
        }
        a = max(b, arr[i].x);
        b = max(b, arr[i].y);
        if (a >= b) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    for (auto i : ansv) {
        cout<<i<<' ';
    }
    return 0;
}
