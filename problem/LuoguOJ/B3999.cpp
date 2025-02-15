//B3999 [洛谷 202406GESP 模拟 四级] 锣鼓工厂
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;

bool cmp(pii p1, pii p2) {
    return p1.x > p2.x;
}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pii> v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i].x;
            v[i].y = i;
        }
        sort(v.begin() + 1, v.end(), cmp);
        vector<pii> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].x;
            arr[i].y = i;
        }
        sort(arr.begin() + 1, arr.end());
        int num = 0;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            num += v[i].x;
            num -= arr[i].x;
            if (num < 0) {
                cout<<"No"<<endl;
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        cout<<"Yes"<<endl;
        for (int i = 1; i <= n; i++) {
            cout << v[i].y << ' ';
        }
        cout << endl;
        for (int i = 1; i <= n; i++) {
            cout << arr[i].y << ' ';
        }
        cout << endl;
    }
    return 0;
}
