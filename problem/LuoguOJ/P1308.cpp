//字符串处理真毒瘤吧
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, ss;
    int cnt = 0, ptr = -1;
    getline(cin, s);
    getline(cin, ss);
    ss.push_back(' ');
    for (int i = 0; i < ss.size()-1; i++) {
        for (int j = 0; j < s.size(); j++) {
            if (ss[i + j] == ' ')break;
            if (toupper(ss[i + j]) != toupper(s[j])) break;
            if ((j == s.size() - 1 && ss[i + j + 1] == ' ')&&(i>0 && ss[i-1] == ' ')) {
                cnt++;
                if (ptr == -1)ptr = i;
            }
        }
    }
    if (ptr == -1) cout << -1;
    else cout << cnt << ' ' << ptr;
    return 0;
}
