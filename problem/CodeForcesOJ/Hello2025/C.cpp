//C
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

void nhir() {
    i32 l, r;
    std::cin >> l >> r;
    auto get = [&](i32 t) {
        i32 res = 0;
        while (t >> res) res++;
        return res - 1;
    };
    i32 a = l | ((1 << get(l ^ r)) - 1);
    i32 b = a + 1;
    i32 c = a == l ? r : l;
    std::cout << a << ' ' << b << ' ' << c << endl;
}

signed main() {
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
