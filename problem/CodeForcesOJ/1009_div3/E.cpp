#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define space << ' '
typedef pair<int, int> pii;
int qu(int i,int j,int k){
    cout<<'?'<<' '<<i<<" "<<j<<" "<<k<<endl;
    int n;
    cin>>n;
    return n;
}
void Solve() {
    int n;
    cin >> n;
    int a = (double)rand()/RAND_MAX*(n-1)+1,b = 2,c = 3;
    while (a==b || b == c || c == a) {
        a = (double)rand()/RAND_MAX*(n-1)+1;
    }
    int cnt = 75;
    while (cnt--) {
        int d = qu(a,b,c);
        if(d == 0){
            break;
        }
        if(cnt&1) b = d;
        else c = d;
    }
    cout<<'!' <<' '<<a<<" "<<b<<" "<<c<<endl;
}

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
