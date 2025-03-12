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
typedef pair<int, int> pii;

struct node {
    ll a, b, c;
    ll d;

    void init() {
        d = (ll) (-(double) b / (2 * a) + 0.5);
    }

    ll cb(int j) {
        return a * j * j + b * j + c;
    }
};
struct aans {
    ll v,a,b;
};
void solve() {
    int n, m;
    cin >> n >> m;
    set<int> dd;
    int cntb = 1, cnte = m;
    vector<node> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
        arr[i].init();
        if (arr[i].d <= cntb) {
            dd.insert(cntb++);
        } else if (arr[i].d > m) {
            dd.insert(cnte++);
        } else {
            for (int j = max(cntb, arr[i].d - n / 2 - 1); j <= min(cnte, arr[i].d + n / 2 + 1); j++) dd.insert(cnte++);
        }
    }
    sort(arr.begin() + 1, arr.end(), [](node a, node b) {
        if (a.c == b.c) return a.d < b.d;
        return a.c < b.c;
    });
    vector<ll> ans(n + 1, 1ll << 62);
    vector<aans> aaaa;
    for (int i = 1; i <= n; i++) {
        // for (auto j: dd) {
        //     aaaa.push_back({arr[i].cb(j),i,j});
        // }
        for (auto j:dd) {
            aaaa.push_back({arr[i].cb(j),i,j});
        }
    }
    vector<bool> st(n+1);
    set<int> se;
    sort(aaaa.begin(), aaaa.end(), [](auto a, auto b) { return a.v < b.v; });
    // for (int i = 0; i < n; i++) {
    //     int t = aaaa[i].y, p = 0;
    //     for (int j: dd) {
    //         if (ans[t] > arr[t].cb(j)) {
    //             ans[t] = arr[t].cb(j);
    //             p = j;
    //         }
    //     }
    //     dd.erase(p);
    // }
    ll sum = 0;
    // sort(ans.begin() + 1, ans.end());
    for (auto i : aaaa) {
        if (st[i.a]) continue;
        if (se.count(i.b)) continue;
        st[i.a] = true;
        se.insert(i.b);
        sum += i.v;
        cout << sum << ' ';
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
