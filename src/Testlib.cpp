#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> A(n);
    for (int &x: A)
        cin >> x;

    int cntx = 0, cnty = 0;
    for (int i: A) {
        if (i > t) cntx++;
        else if (i < t) cnty++;
    }


    if (cntx >= cnty) {
        cout << t + 1 << endl;
    } else {
        cout << t - 1 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}