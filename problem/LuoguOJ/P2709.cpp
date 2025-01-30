#define LOCAL
//P2709 小B的询问
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int n, m, k, arr[N], num[N], ans[N], aa, chunk, mdr, mdl = 1;
vector<pair<int, pair<int, int> > > pro[5000];

inline int quick_read() {
    int x = 0, t = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') t = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * t;
}

inline void add(int a) {
    aa += num[arr[a]] * 2 + 1;
    num[arr[a]]++;
}

inline void del(int a) {
    aa -= num[arr[a]] * 2 - 1;
    num[arr[a]]--;
}

bool sortcmp(const pair<int, pair<int, int> > &p1, const pair<int, pair<int, int> > &p2) {
    return p1.second.second < p2.second.second;
}

int main() {
#ifdef LOCAL
    freopen("inAndoutFile/P2709_1.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    n = quick_read();
    m = quick_read();
    k = quick_read();
    chunk = sqrt(k);
    for (int i = 1; i <= n; i++) {
        arr[i] = quick_read();
    }
    for (int i = 1; i <= m; i++) {
        int l = quick_read();
        int r = quick_read();
        pro[l / chunk].push_back(make_pair(i, make_pair(l, r)));
    }
    for (int i = 1; i < 1000; i++) {
        sort(pro[i].begin(), pro[i].end(), sortcmp);
    }
    for (auto pppir: pro) {
        for (auto p: pppir) {
            while (mdl > p.second.first) add(--mdl);
            while (mdl < p.second.first) del(mdl++);
            while (mdr > p.second.second) del(mdr--);
            while (mdr < p.second.second) add(++mdr);
            ans[p.first] = aa;
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
