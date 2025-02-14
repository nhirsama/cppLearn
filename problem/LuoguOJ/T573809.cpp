//T573809 [语言月赛 202502] 积木重合
//未通过
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    int ax1,ay1,az1,bx1,by1,bz1;
    int ax2,ay2,az2,bx2,by2,bz2;

    cin>>ax1>>ay1>>az1>>bx1>>by1>>bz1;
    cin>>ax2>>ay2>>az2>>bx2>>by2>>bz2;

    if (xnum > 0 && ynum > 0 && znum > 0) {
        cout << xnum * ynum * znum << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
