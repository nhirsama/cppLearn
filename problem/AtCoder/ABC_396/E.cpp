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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int > ans(n+1);
    vector<
    for (int i = 1;i<=m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        int temp = ans[a];
        ans[a] = ans[b]^c;
        ans[b] =  temp^c;
    }
    for (int i = 1;i<=n;i++) {
        cout<<ans[i]<<' ';
    }
    return 0;
}
