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
    ll a,b;
    string ans;
    cin>>a>>b;
    while (b) {
        char aa = a%10,bb = b%10;
        a/=10;
        b/=10;
        if (bb>=aa)ans.push_back(bb-aa+'0');
        else {
            char bbb = b%10;
            b/=10;
            if (bbb == 1) {
                ans.push_back(bb+10-aa+'0');
            }
            else {
                cout<<-1<<endl;
                return ;
            }
        }
    }
    if (a) {
        cout<<-1<<endl;
        return ;
    }
    while (ans.size()>1 && ans.back() == '0') ans.pop_back();
    for (int i = ans.size()-1;~i;i--)cout<<ans[i];
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
