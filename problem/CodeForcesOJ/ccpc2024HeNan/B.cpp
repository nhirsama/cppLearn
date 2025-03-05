#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<>>p;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        p.push({v[i],i});
    }
    int l = 0, ans = 0, m = 0;
    v[0] = 0x3f3f3f3;
    while (l < n) {
        int minn = 0;
        while (p.top().second<l) {
            p.pop();
        }
        minn = p.top().second;
        p.pop();
        m += minn - l;
        ans += m / v[minn];
        m %= v[minn];
        l = minn;
    }
    cout << ans << endl;
    return 0;
}
