//矩阵加速模板
#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
const int N = 5e6 + 10;
unsigned long long fib[N];

void getfib() {
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 5e6 + 4; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    getfib();
    int t;
    cin >> t;
    while (t--) {
        unsigned long long a = 0, b = 0, c = 0;
        int aa;
        cin >> aa;
        for (int i = 1; i <= aa; ++i) {
            int x;
            cin >> x;
            if (x) a += fib[i];
        }
        int bb;
        cin >> bb;
        for (int i = 1; i <= bb; ++i) {
            int x;
            cin >> x;
            if (x) b += fib[i];
        }
        int cc;
        cin >> cc;
        vector<int> st(cc + 2);
        for (int i = 1; i <= cc; ++i) {
            cin >> st[i];
            if (st[i]) c += fib[i];
        }
        int anss = 0;
        unsigned long long d = a * b;
        for (int i = 1; i <= cc; ++i) {
            if (st[i] == 0 && st[i - 1] == 0 && st[i + 1] == 0) {
                if (d == c + fib[i]) {
                    anss = i;
                    break;
                }
            }
        }
        cout << anss << endl;
    }
}
