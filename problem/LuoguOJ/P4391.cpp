//P4391 [BalticOI 2009] Radio Transmission 无线传输
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 10;
#define endl '\n'
int knext[N], l;
string s;

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> l >> s;
    for (int i = 1, j = 0; i < s.size(); i++) {
        j = knext[i - 1];
        while (j && s[i] != s[j]) j = knext[j - 1];
        if (s[i] == s[j]) j++;
        knext[i] = j;
    }
    cout << s.size() - knext[s.size() - 1] << endl;
    return 0;
}
