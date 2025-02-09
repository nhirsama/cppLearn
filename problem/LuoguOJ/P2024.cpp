//P2024 [NOI2001] 食物链
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;

class ccb {
public:
    vector<int> root;

    ccb(int x) {
        root = vector<int>(x + 1);
        for (int i = 1; i <= x; i++) root[i] = i;
    }

    int find(int x) {
        return root[x] == x ? x : root[x] = find(root[x]);
    }

    void merge(int x, int y) {
        root[find(y)] = find(x);
    }

    bool check(int x, int y) {
        return find(x) == find(y);
    }
};
//第一部分是同类，二是天敌，三是食物；
ccb A(N * 3);
int n, k, ans;

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("inAndoutFile/P2024_2.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int a, x, y;
        cin >> a >> x >> y;
        if (x > n || y > n) {
            ans++;
            continue;
        }

        if (a == 1) {
            if (A.check(x+n, y) || A.check(x+2*n, y)) { ans++; } else {
                A.merge(x, y);
                A.merge(x + n, y + n);
                A.merge(x + 2 * n, y + 2 * n);
            }
        } else {
            if (x == y || A.check(x, y) || A.check(x+n, y)) {
                ans++;
                continue;
            } else {
                A.merge(x,y+n);
                A.merge(y,x+n*2);
                A.merge(x+n,y+2*n);

            }
        }
    }
    cout << ans << endl;
    return 0;
}
