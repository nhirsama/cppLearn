//B
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
    int cnt =  0;
    string s;
    cin>>s;
    for(int i = 0;i<s.size();i++){
        if((i+cnt+1)&1){
            if(s[i] != 'i') cnt++;
        }
        else {
            if(s[i] != 'o') cnt++;
        }
    }
    cout<<cnt+((s.size()+cnt)%2 == 1)<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
