//5438. 密接牛追踪2
//P9975 [USACO23DEC] Cowntact Tracing 2 B
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

vector<int> arr;

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (char c: s) {
        if (c == '1') {
            cnt++;
        } else if (cnt) arr.push_back(cnt), cnt = 0;
    }
    if (cnt) arr.push_back(cnt), cnt = 0;
    if (arr.size() == 0) {
        cout<<0<<endl;
        return 0;
    }
    priority_queue<int, vector<int>, greater<> > qu;
    for (int i = 0; i < arr.size(); i++) {
        if ((i == 0 && s[0] == '1') || (i == arr.size() - 1 && s.back() == '1')) {
            qu.push(arr[i] - 1);
        } else qu.push(arr[i] / 2 - (arr[i] % 2 == 0));
    }
    int ans = 0, day = qu.top();
    for (int i = 0; i < arr.size(); i++) {
        ans += max(arr[i]/ (2*day+1)+(arr[i]%(2*day+1)!=0), 1);
    }
    cout << ans << endl;
    return 0;
}
