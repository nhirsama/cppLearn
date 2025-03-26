//D
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
vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}
bool isprime(int n) {
    return minp[n] == n;
}
void nhir() {
    i64 n;
    std::cin>>n;
    i64 cnt = 0,sum = 0,pricnt;
    vector<bool> st(n+1,false);
    for(i32 i = 1;i<=n;i++){
      i64 te = sum+i;
        if(isprime(sum/cnt+sum%cnt !=0))
    }
}

signed main() {;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    sieve(1e5+10);
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
