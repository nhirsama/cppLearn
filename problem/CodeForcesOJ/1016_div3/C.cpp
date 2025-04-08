//C
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9+7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
bool isPrime(i32 n) {
    if (n <= 1) return false;
    for (i32 i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void nhir() {
    i32 n,k;
    std::cin >> n >> k;
    if (n == 1 && k == 2) {
        std::cout<<"YES\n";
    }
    else if(k>1){
        std::cout<<"NO\n";
    }
    else{
        if(isPrime(n)){
            std::cout<<"YES\n";
        }
        else{
            std::cout<<"NO\n";
        }
    }
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin>>T;
    while (T--) nhir();
    return 0;
}
