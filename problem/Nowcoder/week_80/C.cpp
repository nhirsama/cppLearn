#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,win,ans;
bool flag = false;
string s;
int main() {
    cin>>n;
    cin>>s;
    for(int i = 0;i<s.size();i++){
        if(s[i] == '1') {
            win++;
        }
        else {
            if(i-win == win && flag){
                puts("0");
                return 0;
            }
            else if(i-win == win){
                flag = 1;
                ans+=i-win+1;
                win++;
            }
        }
    }
    if(!flag)ans = s.size();
    cout << ans<<endl;
    return 0;
}
