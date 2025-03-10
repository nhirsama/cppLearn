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
    ll n;
    cin >> n;
    vector<ll> v(n*2+10);
    set<ll> s;
    for (ll i = 1; i <= n*2; i++) {
        cin >> v[i];
        s.insert(v[i]);
    }
    sort(v.begin()+1, v.end(), greater<ll>());
    unordered_map<ll, int> mp;
    for (int i = 1; i <= n*2; i+=2) {
        v[0] += v[i]-v[i+1];
        mp[v[i]-v[i+1]] = i;
    }
    while (s.find(v[0]) != s.end() || v[0]<=0) {
        auto ptr = s.find(v[0]);
        if (v[0]-(*--ptr)>1) {
            if (mp.count((v[0]-(*ptr))*2)) {
                int mmm = mp[(v[0]-(*ptr))*2];
                v[0]-=v[mmm]-v[mmm+1];
                swap(v[mmm],v[mmm+1]);
                v[0]+=v[mmm]-v[mmm+1];
                break;
            }
        }
    }
        for (ll i = 0; i <= n*2; i++) {
            cout << v[i] << " ";
        }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
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
