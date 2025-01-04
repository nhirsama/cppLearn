#define LOCAL
//P1013 [NOIP1998 提高组] 进制位
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
map<char,int> ma;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    string s[15][15];
    char a[15][2];
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j<n;j++){
            cin >> s[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
      int m = 0;
        for (int j = 1; j < n; j++) {
            if(s[i][j].size() == 2) m++;
        }
        a[i][0] = s[i][0][0];
        a[i][1] = m;
        ma[a[i][0]] = a[i][1];
        ans++;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (s[i][j].size() == 1 && (ma[s[i][j][0]] != ma[s[i][0][0]]+ma[s[0][j][0]])) {
                cout << "ERROR!" << endl;
                return 0;
            }
            else if (s[i][j].size() == 2 &&( ma[s[i][j][0]]*ans+ma[s[i][j][1]] != ma[s[i][0][0]]+ma[s[0][j][0]])) {
                cout << "ERROR!" << endl;
                return 0;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        cout << a[i][0] << "=" << (char)(a[i][1]+'0') << ' ';
    }
    cout <<endl <<  ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}