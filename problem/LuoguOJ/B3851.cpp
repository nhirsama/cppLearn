#define LOCAL
//B3851 [GESP202306 四级] 图像压缩
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int n;
string str[25];
map<int, int> mp;
int toTen(string s) {
    int ans = 0;
    for (int j = 0; j < s.length(); j++) {
        if ('0' <= s[j] && s[j] <= '9') {
            ans += pow(16,s.size()-j-1)*(s[j]-'0');
        }
        else {
            ans += pow(16,s.size()-j-1)*(s[j]-'A'+10);
        }
    }
    return ans;
}
char to16(int a) {
    if (a < 10) return '0' + a;
    return 'A' + a - 10;
}
bool sortcmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>str[i];
        for (int j = 0; j < str[i].length(); j+=2) {
            mp[toTen(str[i].substr(j,2))]++;
        }
    }
    pair<int ,int> pii[256];
    int idx = 0;
    for (auto p : mp) {
        pii[idx++] = p;
    }
    sort(pii, pii+idx,sortcmp);
    for (int i = 0; i < 16; i++) {
        int a = pii[i].first;
        cout<<to16(a/16)<<to16(a%16);
    }
    cout<<endl;
    for (int i = 0; i < n; i++) {
        string s = str[i];
        for (int j = 0; j < str[i].length(); j+=2) {
            string t = str[i].substr(j,2);
            int ans = 0,d = 0x3f3f3f,to10 = toTen(t);
            for (int k = 0; k < 16;k++) {
                if (abs(to10-pii[k].first)< d) {
                    //编号值更小的灰阶，草，亏我还特判了一下是值更小
                    // if (abs(to10-pii[k].first) == d && pii[k].first<pii[ans].first) {
                    //     ans = k;
                    //     d = abs(to10-pii[k].first);
                    // }
                    ans = k;
                    d = abs(to10-pii[k].first);
                }
            }
            cout<<to16(ans);
        }
        cout<<endl;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}