#include<iostream>
#include<cstdio>

using namespace std;
#define maxn 2000007
#define maxn1 1000007
long long int x, y, tot, n, Head[maxn], Next[maxn], u[maxn], v[maxn];
long long int size2[maxn1], f[maxn1], ans, kkk, dep[maxn1];
bool vis[maxn1], gfg[maxn1];

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline void read(long long &x) {
    int fh;
    char ch;
    x = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') {
        fh = -1;
        ch = getchar();
    } else fh = 1;
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
}

inline void add() {
    u[++tot] = x, v[tot] = y;
    Next[tot] = Head[x], Head[x] = tot;
    u[++tot] = y, v[tot] = x;
    Next[tot] = Head[y], Head[y] = tot; //建边
}

long long int dfs(int x, int root) //求f1和size
{
    int sum = 0;
    vis[x] = 1;
    size2[x] = 1;
    for (int i = Head[x]; i; i = Next[i]) {
        if (vis[v[i]]) continue;
        dep[v[i]] = dep[x] + 1;
        sum += dfs(v[i], x);
    }
    size2[root] = size2[root] + size2[x];
    return sum + dep[x];
}

void zy(int x, int root) //转移
{
    gfg[x] = 1;
    for (int i = Head[x]; i; i = Next[i]) {
        if (gfg[v[i]]) continue;
        f[v[i]] = f[x] + n - 2 * size2[v[i]];
        if (f[v[i]] > ans) {
            ans = f[v[i]];
            kkk = v[i];
        }
        if (f[v[i]] == ans) kkk = min(kkk, v[i]);
        zy(v[i], x);
    }
}

int main() {
    read(n);
    for (register int i = 1; i < n; i++) {
        read(x);
        read(y);
        add();
    }
    f[1] = dfs(1, 0);
    gfg[1] = 1;
    ans = f[1];
    kkk = 1;
    zy(1, 0);
    printf("%d\n", kkk);
}
