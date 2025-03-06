#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve() {
    string s;
    cin>>s;
    int len = s.size()-1;
    int i = 0;
    goto for_loop_begin;
    for(int i = 0;i<s.size();i++,len--){
        cout<<s[i];
        if(len%3==0 && len) cout<<',';
    }
    for_loop_begin:
    cout<<s[i];
    if(len%3==0 && len) cout<<',';
    i++;len--;
    if (i<size()) goto for_loop_begin;
    goto for_loop_end;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
