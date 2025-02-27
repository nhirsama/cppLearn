#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

void Solve() {
    long long n,x,k;
    cin >> n >> x >> k;
    vector<long long> a(n+1),b(n+1);
    a[0]  = x;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if(c == 'L'){
            a[i] = a[i-1] -1;
            b[i] = b[i-1] -1;
        }
        else {
            a[i] = a[i-1] + 1;
            b[i] = b[i-1] + 1;
        }
    }
    long long cnt = 0;
    for (int i = 1; i <= min(n,k); i++) {
        if(a[i] == 0){
            cnt = i;
            break;
        }
    }
    long long cntb = 0;
    for (int i = 1; i <= min(n,k); i++) {
        if(b[i] == 0){
            cntb = i;
            break;
        }
    }
    if(cnt == 0){
        cout << 0 << endl;
    }
    else if (cntb == 0) {
        cout << 1 << endl;
    }
    else {
        // cout << cnt << endl;
        cout << (k-cnt)/cntb+1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
