//模板
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 15;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
int n;
long long ans = 0;
int st[N],stt[N*N],sttt[N*N];
void dfs(int m){
    if(m == n) {
        ans++;
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(st[i]) continue;
        if(stt[i+m+n]) continue;
        if(sttt[i-m+n]) continue;
        st[i] = 1;
        stt[i+m+n] = 1;
        sttt[i-m+n] = 1;
        dfs(m+1);
        st[i] = 0;
        stt[i+m+n] = 0;
        sttt[i-m+n] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        memset(st, 0, sizeof(st));
        memset(stt, 0, sizeof(stt));
        ans = 0;
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}
