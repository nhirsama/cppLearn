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
constexpr i32 mod = 1e9 + 7;

i64 getmod(i64 x) {
    if (x >= 0) return x % mod;
    return -((-x) % mod);
}

int main() {
    i64 t = (1ll * (-100000) * (-10000) * (2));
    cout << getmod(t) << endl;
    return 0;
}
