//P10312 [SHUPC 2024] 栅栏密码
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
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int h;
    cin>>h;
    string s;
    cin>>s;
    vector<vector<char> > vv(h+1);
    int cnt = 1;
    for(char c:s){
        vv[cnt].push_back(c);
        if(cnt<h) cnt++;
        else cnt = 1;
    }
    for(int i  =1;i<=h;i++){
      for(char c:vv[i])
        cout<<c;
    }
    return 0;
}
