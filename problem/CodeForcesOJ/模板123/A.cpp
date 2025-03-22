//A
#include <bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long int i64;
typedef int i32;
typedef short i16;
typedef char i8;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

void nhir() {
    i32 n,k;

    cin>>n>>k;
    string s;
    cin>>s;
    string p = s;
    reverse(s.begin(), s.end());
    set<char> se;
    for (auto c:s) {
        se.insert(c);
    }
    if (se.size() == 1) {
        cout<<"NO"<<endl;
    }
    else{
        if(k==0){
            if(s>p){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else cout<<"YES"<<endl;
    }
}

signed main() {
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
