//P11747 「TPOI-1A」鞋子特大号
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10, P = 1e6 + 5;
typedef long long int ll;
typedef unsigned long long int ull;
#define x first
#define y second
typedef pair<int, int> pii;
bool notprime[P];
int prime[P], primeCnt;

void getPrime() {
    notprime[1] = true;
    for (int i = 2; i < P; i++) {
        if (!notprime[i]) {
            prime[primeCnt++] = i;
        }
        for (int j = 0; i * prime[j] < P; j++) {
            notprime[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
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
    getPrime();
    while (T--) {
        int A,x;
        cin >> A >> x;
        if (A == 1) {
            ll ans = (x == 1);
            for (int i = 0; i < primeCnt && x>1; i++) {
                while (x % prime[i] == 0) {
                    ans++;
                    x /= prime[i];
                }
            }
            cout << ans - 1 << "\n";
        } else {
            cout << (1ull<<x+1) << "\n";
        }
    }
    return 0;
}
