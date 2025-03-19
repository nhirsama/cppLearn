//E. Little Rabbit's Equation
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

i64 get(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    return c - 'A' + 10;
}

void nhir() {
    string s;
    while (cin >> s) {
        i32 ans = -1;
        for (i32 base = 2; base <= 16; base++) {
            i32 op = 0, nu = 1;
            i64 a = 0, b = 0, c = 0;
            i32 j = 1;
            for (i32 i = s.size() - 1; ~i; i--) {
                if (s[i] == '+') op = 1, nu++,j = 1;
                else if (s[i] == '-') op = 2, nu++, j = 1;
                else if (s[i] == '*') op = 3, nu++, j = 1;
                else if (s[i] == '/') op = 4, nu++, j = 1;
                else if (s[i] == '=') nu++, j = 1;
                else if (nu == 1) {
                    if (get(s[i]) >= base) {
                        j = -1;
                        break;
                    }
                    c += get(s[i]) * j;
                    j *= base;
                } else if (nu == 2) {
                    if (get(s[i]) >= base) {
                        j = -1;
                        break;
                    }
                    b += get(s[i]) * j;
                    j *= base;
                } else if (nu == 3) {
                    if (get(s[i]) >= base) {
                        j = -1;
                        break;
                    }
                    a += get(s[i]) * j;
                    j *= base;
                }
            }
            if (j != -1) {
                if (op == 1) {
                    if (a + b == c) {
                        ans = base;
                        break;
                    }
                } else if (op == 2) {
                    if (a - b == c) {
                        ans = base;
                        break;
                    }
                } else if (op == 3) {
                    if (a * b == c) {
                        ans = base;
                        break;
                    }
                } else if (op == 4) {
                    if (a % b == 0 && a / b == c) {
                        ans = base;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    // if (getenv("LOCAL") != nullptr) {
    //     freopen("Testlib.in", "r", stdin);
    //     // freopen("Code.out", "w", stdout);
    // }
    while (T--) nhir();
    return 0;
}
