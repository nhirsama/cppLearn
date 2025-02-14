//T573808 [语言月赛 202502] IPv6
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;

string tob(char a) {
    int aaa;
    string ans;
    if ('0' <= a && a <= '9') {
        aaa = a - '0';
    } else {
        aaa = a - 'A' + 10;
    }
    for (int i = 3; ~i; i--) {
        ans += ((aaa >> i) & 1) + '0';
    }
    return ans;
}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    string s, t, ans;
    cin >> s;
    vector<string> v;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ':') {
            if (t.size() <4 && t.size()) {
                int si = t.size();
                for (int j = si+1; j <=4; ++j) {
                    t = "0"+t;
                }
            }
            if (t != "")v.push_back(t),t = "";
        }
        else {t.push_back(s[i]);}
    }
    if (t.size() <4 && t.size()) {
        int si = t.size();
        for (int j = si+1; j <=4; ++j) {
            t = "0"+t;
        }
    }
    if (t != "")v.push_back(t),t = "";
    if (v.size() < 8) {
        int aaa = (s[0]!=':');
        for (int i = 0; i < s.size()-1; ++i) {
            if (s[i] == ':' && s[i+1] == ':') {
                break;
            }
            if (s[i] == ':')aaa++;
        }
        for (int i = v.size()+1; i <=8; ++i) {
            v.insert(v.begin()+aaa,"0000");
        }
    }
    for (auto i : v) {
          //cout << i << endl;
        for (auto j : i) {
            cout<<tob(j);
        }
        //cout << endl;
    }
    // int num = 0;
    // for (int i = 0; i < s.length(); i++) {
    //     if (s[i] == ':') num++;
    // }
    //
    // if (num < 7) {
    //     int aaa = 0;
    //     for (int i = 0; i < s.length() - 1; i++) {
    //         if (s[i] == ':' && s[i + 1] == ':') aaa = i;
    //     }
    //     string temp = "0000";
    //     for (int i = 1; i <= 7 - num; i++) {
    //         temp += ":0000";
    //     }
    //     s = s.substr(0, aaa + 1) + temp + s.substr(aaa + 1);
    // }
    // int aaa = 0, bbb = 0;
    // for (int i = 0; i < s.length(); i++) {
    //     if (s[i] == ':') {
    //         if (bbb < 4) {
    //             string temp;
    //             for (int j = 1; j <= 4 - bbb; j++) {
    //                 temp += "0";
    //             }
    //             s = s.substr(0, aaa + 1) + temp + s.substr(aaa + 1);
    //         }
    //         i+=4-bbb;
    //         bbb = 0;
    //         aaa = i;
    //     } else bbb++;
    // }
    // if (bbb < 4) {
    //     string temp;
    //     for (int i = 1; i <= 4 - bbb; i++) {
    //         temp += "0";
    //     }
    //     s = s.substr(0, aaa + 1) + temp + s.substr(aaa + 1);
    // }
    // cout << s << endl;
    // for (int i = 0; i < s.length(); i++) {
    //     if (s[i] == ':')continue;
    //     ans += tob(s[i]);
    // }
    // cout << ans << endl;
    return 0;
}
