//P1309 [NOIP 2011 普及组] 瑞士轮
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e6 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<

struct node {
    int s, w, n;
};

typedef pair<int, int> pii;

int n, r, q;
node arr[N];
queue<node> qwin, qlose, qu;

bool sortcomp(const node &a, const node &b) {
    if (a.s == b.s) return a.n < b.n;
    return a.s > b.s;
}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("inAndoutFile/P1309_2.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> r >> q;
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> arr[i].s;
        arr[i].n = i;
    }
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> arr[i].w;
    }
    sort(arr + 1, arr + n * 2 + 1, sortcomp);
    for (int i = 1; i <= 2 * n; ++i) {
        qu.push(arr[i]);
    }
    while (r--) {
        for (int i = 1; i <= n; ++i) {
            auto a = qu.front();
            qu.pop();
            auto b = qu.front();
            qu.pop();
            if (a.w >= b.w) {
                a.s++;
                qwin.push(a);
                qlose.push(b);
            } else {
                b.s++;
                qwin.push(b);
                qlose.push(a);
            }
        }
        while (!qwin.empty() && !qlose.empty()) {
            if (qwin.front().s > qlose.front().s) {
                qu.push(qwin.front());
                qwin.pop();
            } else if (qwin.front().s == qlose.front().s) {
                if (qwin.front().n < qlose.front().n) {
                    qu.push(qwin.front());
                    qwin.pop();
                } else {
                    qu.push(qlose.front());
                    qlose.pop();
                }
            } else {
                qu.push(qlose.front());
                qlose.pop();
            }
        }
        while (!qwin.empty()) {
            qu.push(qwin.front());
            qwin.pop();
        }
        while (!qlose.empty()) {
            qu.push(qlose.front());
            qlose.pop();
        }
    }
    for (int i = 1; i < q; ++i) {
        qu.pop();
    }
    cout << qu.front().n endl;
    return 0;
}
