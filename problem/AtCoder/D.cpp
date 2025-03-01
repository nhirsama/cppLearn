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
    int n,q;
    cin>>n>>q;
    vector<int> v(n + 1);
    vector<int> cc(n + 1);
    vector<int> dd(n + 1);
    for(int i = 1;i<=n;i++){
        v[i] = i;
        cc[i] = i;
        dd[i] = i;
    }

    while(q--){
        int aa,bb,ccc;
        cin>>aa;
        if(aa==1){
            cin>>bb>>ccc;
            dd[bb] = v[ccc];
        }
        if(aa == 2){
            cin>>bb>>ccc;
            int ta = v[bb];
            int tb = v[ccc];
            swap(v[bb], v[ccc]);
            swap(cc[ta], cc[tb]);
        }
        if(aa == 3){
            cin>>ccc;
            cout<<cc[dd[ccc]]<<endl;
        }
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
