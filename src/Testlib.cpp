#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mac=1e5+10;
const ll inf=1e18+7;
const int INF=1e7+10;

struct edge
{
    int next, to, f;
    ll w;
}eg[mac << 1];
int head[mac], num = 1;
int pre[mac], vis[mac],flows[mac];
int s, t, maxflow, flag[mac];
ll dis[mac];

inline void add(int u, int v, int f, ll w)
{
    eg[++num].to = v; eg[num].next = head[u]; eg[num].f = f;
    eg[num].w = w; head[u] = num;

    eg[++num].to = u; eg[num].next = head[v]; eg[num].f = 0;
    eg[num].w = -w; head[v] = num;
}
void update(int x, int flow)
{
	eg[pre[x]].f -= flow;
	eg[pre[x] ^ 1].f += flow;
	if (eg[pre[x] ^ 1].to)update(eg[pre[x] ^ 1].to, flow);
}
inline ll spfa()
{
	memset(vis, 0, sizeof(vis));
	queue<int>q;
	for (int i = 0; i <= t; i++) dis[i] = inf;
	flows[s] = INF; dis[s] = 0; q.push(s); vis[s] = 1;
	while (!q.empty()){
		int u = q.front();
		q.pop(); vis[u] = 0;
		for (int i = head[u]; i!=-1; i = eg[i].next){
			int v = eg[i].to;
			if (dis[v] > dis[u] + eg[i].w && eg[i].f){
				dis[v] = dis[u] + eg[i].w;
				pre[v] = i;
				flows[v] = min(flows[u], eg[i].f);
				if (!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	if (dis[t] == inf) return inf;
	maxflow += flows[t];
	update(t, flows[t]);
	return (ll)flows[t] * dis[t];
}
ll a[mac],b[mac],c[mac];

ll fff(int i,ll x)
{
	return a[i]*x*x+b[i]*x+c[i];
}

int pot[60][60];

void init()
{
	memset(head,-1,sizeof head);
	memset(flows,0,sizeof flows);
	memset(pre,0,sizeof pre);
	num=1;
}

int main(int argc, char const *argv[])
{
	int Cas;
	scanf ("%d",&Cas);
	while (Cas--){
		init();
		int n,m;
		scanf ("%d%d",&n,&m);
		for (int i=1; i<=n; i++){
			scanf ("%lld%lld%lld",&a[i],&b[i],&c[i]);
			int l=1,r=m,ans;
			while (l<r){
				int mid1=floor(1.0*(2*l+r)/3);
				int mid2=floor(1.0*(l+2*r+2)/3);
				if (fff(i,mid1)<fff(i,mid2)){
					ans=mid1;
					r=mid2-1;
				}
				else {
					ans=mid2;
					l=mid1+1;
				}
			}
			int cnt=1;
			pot[i][cnt]=ans;//三分出的当前区域的最小值点
			l=ans-1,r=ans+1;//由最优质点向两边拓展n个点
			while (cnt<n){
				if (fff(i,l)<fff(i,r)){
					if (l>=1 && l<=m) {
						pot[i][++cnt]=l;
						l--;
					}
					else {
						pot[i][++cnt]=r;
						r++;
					}
				}
				else {
					if (r>=1 && r<=m){
						pot[i][++cnt]=r;
						r++;
					}
					else {
						pot[i][++cnt]=l;
						l--;
					}
				}
			}
		}
		unordered_map<int,int>q;//给每个点标号
		int cnt=0;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if (!q[pot[i][j]]){
				 	q[pot[i][j]]=++cnt;
				}
			}
		}
		s=0;t=cnt+n+1;
		for (int i=1; i<=n; i++){
			add(s,cnt+i,1,0);
			for (int j=1; j<=n; j++){
				add(cnt+i,q[pot[i][j]],1,fff(i,pot[i][j]));
			}
		}
		for (int i=1; i<=cnt; i++) add(i,t,1,0);
		ll ans=0;
		for (int i=1; i<=n; i++){
			ll x=spfa();//每次跑个残余网络
			printf("%lld%c",ans+x,i==n?'\n':' ');
			ans+=x;
		}
	}
	return 0;
}
