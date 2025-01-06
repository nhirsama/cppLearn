#define LOCAL
//SP3267 DQUERY - D-query
//莫队真乃神人也
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 30005,M = 1e6+5;
int n,num[M],cnt[M],l = 1,r,qnum,nowAns,ans[M],len;
struct node{
    int l,r,id;
}q[200005];
bool cmp(const node &a,const node &b){
    if (a.l/len==b.l/len) {
        return a.r<b.r;
    }
    return a.l/len<b.l/len;
}
void add(int i) {
    if (!cnt[num[i]]) nowAns++;
    cnt[num[i]]++;
}
void del(int i) {
    cnt[num[i]]--;
    if (!cnt[num[i]]) nowAns--;

}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    scanf("%d",&qnum);
    for(int i=1;i<=qnum;i++) {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    len = max(1, (int)sqrt((double)n * n / qnum));
    sort(q+1,q+qnum+1,cmp);
    for(int i=1;i<=qnum;i++) {
        while (l<q[i].l) del(l++);
        while (l>q[i].l) add(--l);
        while (r<q[i].r) add(++r);
        while (r>q[i].r) del(r--);
        ans[q[i].id]=nowAns;
    }
    for(int i=1;i<=qnum;i++) printf("%d\n",ans[i]);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}