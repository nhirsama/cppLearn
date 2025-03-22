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
    i32 n;
    cin >> n;
    vector<i32> v(n + 1);
    i32 zero = 0;
    for (i32 i = 1; i <= n; i++) {
        cin >> v[i];
        if (!v[i])zero++;
    }
    if (zero == 0) {
        cout<<1<<endl;
        cout<<1<<' '<<n<<endl;
    }
    else if (v[1] ==0 && v[n] == 0) {
        cout<<3<<endl;
        cout<< 1<<' '<<n/2<<endl;
        cout<<2<<' '<<(n-(n/2-1))<<endl;
        cout<<1<<' '<<2<<endl;
    }
    else if (v[1] != 0) {
        cout<<2<<endl;
        cout<< 2<< ' '<<n<<endl;
        cout<<1<<' '<<2<<endl;
    }
    else if (v[n] !=0) {
        cout<<2<<endl;
        cout<< 1<< ' '<<n-1<<endl;
        cout<<1<<' '<<2<<endl;
    }
    // i32 zero = 0, other = 0;
    // for (i32 i = 1; i <= n; i++) {
    //     cin >> v[i];
    //     if (v[i]) other++;
    //     else zero++;
    // }
    // if (other == 0) {
    //     cout << 3 << endl;
    //     cout << 1 << ' ' << n / 2 << endl;
    //     cout << 2 << ' ' << n - (n / 2 - 1) << endl;
    //     cout << 1 << ' ' << 2 << endl;
    // } else if (zero == 0) {
    //     cout << 1 << endl;
    //     cout << 1 << ' ' << n << endl;
    // } else {
    //     i32 k = 0;
    //     vector<i32> aa;
    //     vector<pii> ans;
    //     aa.push_back(0);
    //     i32 i = 1, l = 0, del = 0;
    //     for (; i <= n; i++) {
    //         if (v[i] != 0) {
    //             if (i - l > 2) {
    //                 aa.push_back(1);
    //                 aa.push_back(v[i]);
    //                 ans.push_back(pii(l - del + 1, i - 1 - del));
    //                 k++;
    //                 del += i - l - 1;
    //             } else if (i - l == 2) {
    //                 aa.push_back(0);
    //                 aa.push_back(v[i]);
    //             } else {
    //                 aa.push_back(v[i]);
    //             }
    //             l = i;
    //         }
    //     }
    //     i--;
    //     if (i - l > 1) {
    //         aa.push_back(1);
    //         ans.push_back(pii(l - del + 1, i - del));
    //     } else if (i - l == 1) aa.push_back(0);
    //     del = 0;
    //     for (i32 j = 1; j < aa.size(); j++) {
    //         if (aa[j] == 0 || aa[j + 1] == 0) {
    //             k++;
    //             ans.push_back(pii(j - del, j + 1 - del));
    //             j++;
    //             del++;
    //         }
    //     }
    //     if (del < aa.size() - 1) {
    //         ans.push_back(pii(1, aa.size() - 1 - del));
    //     }
    //     cout << ans.size() << endl;
    //     for (auto [x,y]: ans) {
    //         cout << x << ' ' << y << endl;
    //     }
    // }
}

signed main() {
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
