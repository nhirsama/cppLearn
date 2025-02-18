#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

void Func(){
    string s;
    cin >> s;
    int i = 0, j = 0;
    for(int k = 0; k < s.length(); k++){
        if(s[k] != s[s.length() - 1-k]){
            if(!i) i = k;
            j = k;
        }
    }
    cout << min(j-i+1,(int)s.length()-1) endl;
}
int main() {
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
