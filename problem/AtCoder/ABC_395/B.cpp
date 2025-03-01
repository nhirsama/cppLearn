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
    vector g(n+1,vector<char>(n+1,'#'));
    int l = 2,r = n-1;
    while(l<=r){
        for(int i =l;i<=r;i++){
            g[i][l] = '.';
            g[i][r] = '.';
            g[l][i] = '.';
            g[r][i] = '.';
            }
            l+=2;
            r-=2;
    }
    for(int i = 1;i<=n;i++){
        for(int j  =1;j<=n;j++){
            cout<<g[i][j];
        }
        cout<<endl;
    }
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
