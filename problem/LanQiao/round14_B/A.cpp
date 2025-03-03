#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

ll read() {
    ll ans = 0;
    bool flag = false;
    char c = cin.get();
    while (c < '0' || c > '9') {
        if (c == '-') flag = true;
        c = cin.get();
    }
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = cin.get();
    if (flag) return -ans;
    return ans;
}
int arr[101];
int st[101];
set<int> s;
void dfs(int n,long long num,int m){
    if (n == 1) if (num!=2) return ;
    if (n == 2) if (num!=20) return ;
    if (n == 3) {
        if (num!=202) return;
    }

    if(n == 4){
        if(num != 2023) return;
    }
    if(n == 6){
        int mm = num%100;
        if(0==mm || mm>=13) return ;
    }
    if(n == 8){
        int dd = num%100;
        if(dd>32 || dd==0) return ;
        // cout<<num endl;
        s.insert(num);
        return;
    }
    for(int i = m;i<=100;i++){
        if(st[i]) continue;
        st[i] = 1;
        dfs(n+1,num*10+arr[i],i);
        st[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 100;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    dfs(0,0,8);
    cout<<s.size() endl;
    for(int i :s) cout<<i endl;
    return 0;
}
