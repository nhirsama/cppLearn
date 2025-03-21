//P2251 质量检测
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
    i32 n, m;
    cin >> n >> m;
    vector<i32> arr(n + 1);
    for (i32 i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    deque<i32> q;
    for (i32 r = 1; r <= n; r++) {
        while (!q.empty() && arr[q.back()] >= arr[r]) q.pop_back();
        q.push_back(r);
        while (q.front() <= r - m) q.pop_front();
        if (r >= m)cout << arr[q.front()] << endl;
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
