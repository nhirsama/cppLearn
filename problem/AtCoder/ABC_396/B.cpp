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
    stack <int> s;
    for(int i = 1;i<=100;i++) s.push(0);
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        if(x == 1){
            int y;
            cin>>y;
            s.push(y);
        }
        else {
            cout<<s.top()<<endl;
            s.pop();
        }
    }
    return 0;
}
