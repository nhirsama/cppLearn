// code by Elaina
#include <bits/stdc++.h>
#define cno cout << "NO\n"
#define cyes cout << "YES\n"
#define endl '\n'
#define N 200010
using namespace std;
using ll = long long;
ll t, n, ans;
ll a[N], b[N],p1[N],p2[N];
void solve()
{
    ans = 0;
    cin >> n;
    memset(p1, -1, sizeof(p1));
    memset(p2, -1, sizeof(p2));
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = n; i >= 1; --i)
    {
        if(a[i]==b[i])
        {
            ans=i;
            break;
        }
        if(p1[a[i]]!=-1||p2[b[i]]!=-1){
            ans = i;
            break;
        }
        else if(p1[b[i]]>i+1||p2[a[i]]>i+1){
            ans = i;
            break;
        }
        p1[a[i]] = i, p2[b[i]] = i;
    }

    cout << ans << endl;
}

int main()
{
    freopen("Code.out", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
        solve();
    return 0;
}