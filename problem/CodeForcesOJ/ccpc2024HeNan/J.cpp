#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve() {
    string s;
    cin>>s;
    for (int i = 0;i<5;i++) {
        if ((s[i]-'0')%2==0) {
            if (s[4] != '0') swap(s[i],s[4]);
            cout<<s<<endl;
            return ;
        }
    }
    cout<<97531<<endl;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
