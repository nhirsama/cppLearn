#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,ans  =0;
    cin>>n;
    while(n--){
       string s;
       cin>>s;
       if(s.size() == 5 && s[2] == s[4]){
           set<char> ss;
           for(int i = 0;i<5;i++){
               ss.insert(s[i]);
           }
           if(ss.size() == 4) ans++;
       }
    }
    cout<<ans;
    return 0;
}
