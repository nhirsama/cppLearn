//T573805 [语言月赛 202502] 披萨订单
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    int x, y, k;
    cin >> x >> y >> k;
    int maxm = -1;
    int count = 0;
    for (int b = 0; b <= x; ++b) {
        for (int p = 1; p <= y; ++p) {
            for (int z = 0; z <= k; ++z) {
                int aaa= (b + p) ^ z;

                if (aaa > maxm) {
                    maxm = aaa;
                    count = 1;
                } else if (aaa == maxm) {
                    count++;
                }
            }
        }
    }
    cout << maxm << endl;
    cout << count << endl;
    return 0;
}