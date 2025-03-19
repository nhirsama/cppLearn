//P10426 [蓝桥杯 2024 省 B] 宝石组合
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

void nhir() {
    i64 n;
    cin >> n;
    vector<i64> arr(n + 1), yinshu(1e5 + 10);
    for (i32 i = 1; i <= n; i++) {
        cin >> arr[i];
        for (i32 j = 1; j * j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                if (j*j!=arr[i]) {
                    yinshu[j]++;
                    yinshu[arr[i]/j]++;
                }
                else yinshu[j]++;
            }
        }
    }
    i32 ans = 0;
    for (i32 i = 1; i <= 1e5; i++) {
        if (yinshu[i] >= 3) ans = i;
    }
    sort(arr.begin()+1,arr.end());
    i32 cnt = 0;
    for (i32 i = 1; i <= n; i++) {
        if (arr[i] % ans == 0) {
            cout << arr[i] << ' ';
            cnt++;
        }
        if (cnt >= 3)break;
    }
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
