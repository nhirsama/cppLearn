#include <bits/stdc++.h>
using namespace std;
const int maxn=(2e6)+10;
int T,n,m,a[maxn];
int pre[maxn],suf[maxn];
namespace Tpre {
    int tr[maxn];
    void add(int x,int y) {
        for (;x<=m;x+=x&(-x)) tr[x]=max(tr[x],y);
    }
    int query(int x) {
        int res=0;
        for (;x;x-=x&(-x)) res=max(res,tr[x]);
        return res;
    }
    void clear() { for (int i=1;i<=m;i++) tr[i]=0; }
};
namespace Tsuf {
    int tr[maxn];
    void add(int x,int y) {
        for (;x;x-=x&(-x)) tr[x]=max(tr[x],y);
    }
    int query(int x) {
        int res=0;
        for (;x<=m;x+=x&(-x)) res=max(res,tr[x]);
        return res;
    }
    void clear() { for (int i=1;i<=m;i++) tr[i]=0; }
};
int vis[maxn],M[maxn],N[maxn],Q[maxn],H[maxn];
int b[maxn],tot;
int calc(vector<int> &vec) {
    Tpre::clear();
    int res=0;
    for (int &x : vec) {
        int mx=Tpre::query(x)+1;
        Tpre::add(x,mx);
        res=max(res,mx);
    }
    return res;
}
bool chk() {
    vector<int> v1,v2;
    for (int i=1;i<=n;i++) v1.push_back(a[i]);
    for (int i=1;i<=tot;i++) v1.push_back(b[i]);
    for (int i=1;i<=tot;i++) v2.push_back(b[i]);
    for (int i=1;i<=n;i++) v2.push_back(a[i]);
    if (calc(v1)==calc(v2)) return 1;
    return 0;
}
int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        Tpre::clear(),Tsuf::clear();
        for (int i=1;i<=n;i++) {
            pre[i]=Tpre::query(a[i]-1)+1;
            Tpre::add(a[i],pre[i]);
        }
        for (int i=n;i>=1;i--) {
            suf[i]=Tsuf::query(a[i]+1)+1;
            Tsuf::add(a[i],suf[i]);
        }
        for (int i=1;i<=m;i++) vis[i]=0;
        for (int i=1;i<=n;i++) vis[a[i]]=1;
        tot=0;
        for (int i=1;i<=m;i++) if (!vis[i]) b[++tot]=i;
        reverse(b+1,b+tot+1);
        int base=0;
        for (int i=1;i<=n;i++) base=max(base,suf[i]);
        {
            Tpre::clear();
            for (int k=1;k<=n;k++) Tpre::add(a[k],pre[k]);
            for (int j=1;j<=tot;j++) {
                N[j]=Tpre::query(b[j]);
            }
            for (int i=1;i<=tot;i++) {
                H[i]=max(H[i-1],N[i]+i);
            }
            Tsuf::clear();
            for (int k=1;k<=n;k++) Tsuf::add(a[k],suf[k]);
            for (int j=1;j<=tot;j++) M[j]=Tsuf::query(b[j]);
            for (int i=1,now=-(1e9);i<=m;i++) {
                now=max(now,M[i]-i+1);
                Q[i]=now+i;
                Q[i]=max(Q[i],max(base,M[tot]+1));
            }
            int fd=0;
            for (int i=1;i<=tot;i++) if (Q[i]==H[i]) {
                fd=i; break;
            }
            if (fd) {
                reverse(b+1,b+fd+1);
                puts("Yes");
                for (int i=1;i<=tot;i++) printf("%d ",b[i]); puts("");
                assert(chk());
                continue;
            }
        }
        {
            Tsuf::clear();
            for (int k=1;k<=n;k++) Tsuf::add(a[k],suf[k]);
            for (int j=1;j<=tot;j++) N[j]=Tsuf::query(b[j]);
            for (int i=tot,now=-(1e9);i>=1;i--) {
                now=max(now,N[i]-i+1);
                Q[i]=now+tot;
            }
            Tpre::clear();
            for (int k=1;k<=n;k++) Tpre::add(a[k],pre[k]);
            for (int j=1;j<=tot;j++) M[j]=Tpre::query(b[j]);
            for (int i=tot,now=-(1e9);i>=1;i--) {
                now=max(now,M[i]+i+1);
                H[i]=now-i;
                H[i]=max(H[i],max(base,M[i]+1));
            }
            int fd=0;
            for (int i=1;i<=tot;i++) if (Q[i]==H[i]) {
                fd=i; break;
            }
            if (fd) {
                reverse(b+fd,b+tot+1);
                puts("Yes");
                for (int i=1;i<=tot;i++) printf("%d ",b[i]); puts("");
                assert(chk());
                continue;
            }
        }
        puts("No");
    }
    return 0;
}