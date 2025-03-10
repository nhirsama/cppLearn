//P1082 [NOIP 2012 提高组] 同余方程
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
ll x,y;

void exgcd(long long a, long long b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b);
    ll tx = x;
    x = y;
    y = tx - a / b * y;
    return;
}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    exgcd(a, b);
    x = (x % b + b) % b;
    cout << x << endl;
    return 0;
}
