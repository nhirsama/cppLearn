#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

void Func() {
    int n;
    cin >> n;
    vector<pii> ans;
    int x = 1,y = 1;
    if (!n) {
        cout<<"1\n 1 \n 2"<<endl;
        return ;
    }
    while (n) {
        int m = 0;
        while (m * (m - 1) / 2 <= n) {
            ans.push_back({x++,y});
            m++;
        }
        m--;
        ans.pop_back();
        n -= (m * (m - 1) / 2);
        y++;
    }
    cout<<ans.size()<<endl;
    for (auto [a,b]: ans) {
        cout << a << ' ' << b << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
