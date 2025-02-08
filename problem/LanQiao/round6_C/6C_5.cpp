#include <bits/stdc++.h>
using namespace std;
int a = 0;
bool v[15];

void dfs(string s, int n) {
    if (n == 3) {
        if (s[0] + s[1] != s[2])return;
    }
    if (n == 6)if (s[3] - s[4] != s[5]) return;
    if (n == 9)if (s[6] * s[7] != s[8]) return;
    if (n == 12) {
        if (s[9] == s[10] * s[11]) a++;
        return;
    }
    for (int i = 1; i <= 13; i++) {
        if (v[i]) continue;
        v[i] = true;
        string s1 = s;
        s1.push_back(i);
        dfs(s1, n + 1);
        v[i] = false;
    }
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    dfs("", 0);
    cout << a << endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
