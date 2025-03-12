//模板
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    //四的倍数为yes，奇数且有一个1为yes，
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    if (n % 4 == 0) {
        cout << "YES" << endl;
        return 0;
    } else if (n & 1) {
        for (int i = 1; i <= n; i++) {
            if (arr[i]) {
                cout << "YES" << endl;
                return 0;
            }
        }
    } else {
        int odd = 0, even = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] && i & 1) even++;
            if (arr[i] && i % 2 == 0) odd++;
        }
        if (even && odd) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
