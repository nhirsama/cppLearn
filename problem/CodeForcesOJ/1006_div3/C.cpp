#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

void Func(){
    int n,x;
    cin>>n>>x;
    int temp = 0;
    int cnt = 0;
    for(int i = 0; i < n-1; i++) {
        if ((x|temp|i) == x) {
            cout << i<< ' ';
            temp = i|temp;
            cnt++;
        }
        else break;
    }
    for (;cnt<n-1;cnt++) {
        cout << 0 << ' ';
    }
    if ((temp|(n-1)) == x) {
        cout << n-1<< endl;
    }
    else {
        cout << x << endl;
    }
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
