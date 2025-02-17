//P3374 【模板】树状数组 1
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
typedef pair<int, int> pii;

class TreeArray {
public:
    vector<int> tree;
    int size;

    TreeArray(int n) {
        size = n;
        tree = vector<int>(n+1,0);
    }

    static int lowbit(int x) {
        return x & -x;
    }

    int getsum(int x) const {
        int sum = 0;
        while (x) {
            sum += tree[x];
            x -= lowbit(x);
        }
        return sum;
    }

    void update(int x, int k) {
        for (int i = x; i <= size; i += lowbit(i)) {
            tree[i] += k;
        }
    }
};

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    TreeArray tree(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        tree.update(i,x);
    }
    for (int i = 1; i <= m; i++) {
        int x,y, z;
        cin >> x >> y >> z;
        if (x == 2) {
            cout << tree.getsum(z) - tree.getsum(y-1) << endl;
        } else {
            tree.update(y, z);
        }
    }
    return 0;
}
