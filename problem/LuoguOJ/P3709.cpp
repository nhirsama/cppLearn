//P3709 大爷的字符串题
//P1997 faebdc 的烦恼 需将最后答案的负号去掉
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int arr[N], n, m, chunk, lptr = 1, rptr, ans[N], cnt[N],nowAns,num[N], bit[N];

struct node {
    int l, r, id;
} p[N];

unordered_map<int, int> mp;

bool sortcmp(const node &p1, const node &p2) {
    if (p1.l / chunk == p2.l / chunk) {
        if (p1.l /chunk &1)return p1.r > p2.r;
        return (p1.r < p2.r);
    }
    return (p1.l / chunk < p2.l / chunk);
}

void add(int i) {
    if (nowAns == bit[arr[i]]) nowAns++;
    cnt[bit[arr[i]]] --;
    bit[arr[i]]++;
    cnt[bit[arr[i]]] ++;
}

void del(int i) {
    if (nowAns == bit[arr[i]] && cnt[bit[arr[i]]] == 1)nowAns --;
    cnt[bit[arr[i]]] --;
    bit[arr[i]]--;
    cnt[bit[arr[i]]] ++;
}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        mp[arr[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        arr[i] = mp[arr[i]];
    }
    chunk = sqrt(n);
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        p[i] = {l, r, i};
    }
    sort(p + 1, p + m + 1, sortcmp);
    for (int i = 1; i <= m; i++) {
        while (lptr < p[i].l) del(lptr++);
        while (lptr > p[i].l) add(--lptr);
        while (rptr < p[i].r) add(++rptr);
        while (rptr > p[i].r) del(rptr--);
        ans[p[i].id] = nowAns;
    }
    for (int i = 1; i <= m; i++) {
        printf("%d\n", -ans[i]);
    }
    return 0;
}
