//P11452 [USACO24DEC] Cake Game S
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

ll read() {
    ll ans = 0;
    bool flag = false;
    char c = cin.get();
    while (c < '0' || c > '9') {
        if (c == '-') flag = true;
        c = cin.get();
    }
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = cin.get();
    if (flag) return -ans;
    return ans;
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
        n = read();
        vector<ll> arr(n+1);
        ll anse = 0;
        for (int i = 1; i <= n; i++) {
            arr[i] = read();
            arr[i] += arr[i-1];
        }
        for(int i = 0; i<=n/2-1;i++){
            anse = max(anse, arr[i] + arr[n]-arr[n/2+1+i]);
        }
        cout<<arr[n]-anse space anse endl;
    }
    return 0;
}
