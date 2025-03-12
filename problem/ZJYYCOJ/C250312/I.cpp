//模板
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '
#define WA AC
#define TLE AC
#define MLE AC
#define RE AC
#define CE AC
typedef pair<int, int> pii;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k;
    string s;
    cin>>s>>k;
    sort(s.begin(),s.end());
    while(--k) next_permutation(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}
