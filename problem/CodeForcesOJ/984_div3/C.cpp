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
    string s;
    std::cin >> s;
    i32 q;
    std::cin >> q;
    i64 cnt = 0;
    auto find = [&](i32 begin, i32 end) {
        i32 res = 0;
        for (i32 i = std::max(begin, 0); i < std::min(s.size() - 3, 1ull * end); i++) {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') res++;
        }
        return res;
    };
    for (i32 i = 0; i < s.length() - 3; i++) {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') { cnt++; }
    }
    while (q--) {
        i32 i;
        char c;
        std::cin >> i >> c;
        i--;
        if (c == s[i]) {
            if (cnt) std::cout << "YES\n";
            else std::cout << "NO\n";
        } else {
            cnt -= find(i - 4, i + 4);
            s[i] = c;
            cnt += find(i - 4, i + 4);
            if (cnt) std::cout << "YES\n";
            else std::cout << "NO\n";
        }
    }
}

signed main() {
    ;
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
