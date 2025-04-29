//C
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<int> A, B;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') A.push_back(i + 1);
        else B.push_back(i + 1);
    }

    int maxB = *max_element(B.begin(), B.end());
    for (int a: A) {
        if (a == 1) {
            if (B.size() == 1 && B[0] == n) {
                std::cout << "Alice\n";
                return;
            }
        } else if (a == n) {
            if (find(B.begin(), B.end(), 1) == B.end()) {
                std::cout << "Alice\n";
                return;
            }
        } else {
            if (a > maxB) {
                std::cout << "Alice\n";
                return;
            }
        }
    }
    std::cout << "Bob\n";
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
