//P10194 [USACO24FEB] Milk Exchange G
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s = s.substr(s.size()-1)+s;
    vector<int> arr(n+1),sum(n+1);
    ll minn = 0;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    arr[0] = arr[n];
    for(int i = 1;i<=n;i++){
        if (s[i-1]=='R' && s[i] == 'L') minn+=arr[i-1]+arr[i];
    }

    cout<<minn<<endl;
    return 0;
}
