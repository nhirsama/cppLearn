#define LOCAL
//C. 石头剪刀布
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
char getWin(char a, char b) {
    switch (a) {
        case 'R': {
            if (b != 'P')
                return 'P';
            return 'R';
        }
        case 'P': {
            if (b != 'S')
                return 'S';
            return 'P';
        }
        case 'S': {
            if (b != 'R')
                return 'R';
            return 'S';
        }
    }
    return 'A';
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<char> v(n+1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    vector<char> v2(n+1);
    for (int i = 0; i < n; i++) {
        if (i == 0)v2[i] =getWin(v[i],'A');
        else {
            v2[i] = (getWin(v[i],v2[i-1]));
        }
    }
    for (int i = 0; i < n; i++) {
        if (v2[i]!=v[i])ans++;
    }
    for (int i = n-1; ~i; i--) {
        if (i == n-1)v2[i] =getWin(v[i],'A');
        else {
            v2[i] = (getWin(v[i],v2[i+1]));
        }
    }
    int ans2 = 0;
    for (int i = 0; i < n; i++) {
        if (v2[i]!=v[i])ans2++;
    }
    cout << max(ans,ans2) << endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
