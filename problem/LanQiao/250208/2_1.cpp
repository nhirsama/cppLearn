//模板
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
string s1,s2;
int ans;
int main() {
    int n;
    cin >> n;
    cin >> s1 >> s2;
    int s11 =0 ,s21 = 0;
    for (int i = 0; i < n; i++) {
        if(s1[i] == '1') s11++;
        if(s2[i] == '1') s21++;
    }
    ans = 2*n -s11 - s21;
    ans = min(ans,s11+s21);
    cout << ans << endl;
    return 0;
}
