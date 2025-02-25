#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<
typedef pair<int, int> pii;
int find(int k) {
    if (k == 0) return 0;
    int low = 2, high = 2e5;
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if ((long long)mid * (mid - 1) / 2 <= k) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
void Func(){

}
int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
