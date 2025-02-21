//P1091 [NOIP 2004 提高组] 合唱队形
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1000 + 10;
typedef long long int ll;
#define endl << '\n'
#define space << ' ' <<
int udp[N], ldp[N], arr[N];

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        udp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j]) udp[i] = max(udp[i], udp[j] + 1);
        }
    }
    for (int i = n; i; i--) {
        ldp[i] = 1;
        for (int j = n; j > i; j--) {
            if (arr[i] > arr[j]) ldp[i] = max(ldp[i], ldp[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, ldp[i] + udp[i] - 1);
    }
    cout << n - ans endl;
    return 0;
}
