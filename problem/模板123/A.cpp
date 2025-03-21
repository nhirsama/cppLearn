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

void LingRhythm() {
    string x;
    cin>>x;
    swap(x[0],x[2]);
    while(x.size() && x.front() == '0') x.erase(x.begin());
    if (x.size() == 0)x.push_back('0');
    cout<<x<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) LingRhythm();
    return 0;
}
