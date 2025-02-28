//P10131 [USACO24JAN] Majority Opinion B
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

void Solve() {
    int n;
    cin >> n;
    set<int> ans;
    vector<int> arr(n+1);
    for (int i = 1;i<=n;i++) {
        cin>>arr[i];
    }
    for (int i  =2;i<=n;i++) {
        if (arr[i] == arr[i-1] || arr[i-2]==arr[i])ans.insert(arr[i]);
    }
    if (ans.size()) {
        for (auto i :ans)cout<<i space;
    }
    else {
        cout<<-1;
    }
    cout<<endl;
}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
