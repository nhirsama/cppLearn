#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<pair<int, string> > s;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        string b;
        cin >> b >> a;
        s.push_back(make_pair(a, b));
        ans += a;
    }
    ans /= n;
    int temp = 0x3f3f3f3f;
    cout << ans / 2 << ' ';
    string name;
    for (auto i: s) {
        if (abs(i.first - ans / 2) < temp) name = i.second, temp = abs(i.first - ans / 2);
    }
    cout << name;
}
