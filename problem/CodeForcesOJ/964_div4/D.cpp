#include <bits/stdc++.h>
using namespace std;
void Func(){
    string s,t;
    cin>>s;
    cin>>t;
    int i = 0,h = 0;
    for(;i<s.length()&&h<t.size();i++){
        if(s[i]==t[h]){
            h++;
        }
        if(s[i] == '?'){
            s[i]=t[h];
            h++;
        }
    }
    if(h == t.size()){
        cout<<"YES"<<endl;
        for(;i<s.length();i++) {
            if(s[i]=='?') {
                s[i]=s[0];
            }
        }
        cout<<s<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}
int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
