#define LOCAL
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
    cin>>n;
    vector<int> v(n+1);
    bool flag = 1;
    for(int i = 1;i<=n;i++){
        cin>>v[i];
        if(v[i]<=v[i-1]) flag = false;
    }
    if(flag) cout<<"Yes";
    else cout<<"No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T;
    T = 1;
    while (T--) {
        Solve();
    }
    return 0;
}
