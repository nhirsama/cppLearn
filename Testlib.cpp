#define LOCAL
//改变思路：看k每一次自增能解决什么问题
//所以要将提出的问题存到一个数组里
#include<cstdio>
#include<cstring>
using namespace std;
bool b[201];
int n,m,x,y,z,q,t[201],f[201][201];
int from[50001],to[50001],day[50001];//questions;
int main()
{
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Testlib.out", "w", stdout);
#endif
    memset(f,0x7f,sizeof(f));
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++)
        f[i][i]=0;//初始化
    for (int i=0; i<n; i++)//注意从0开始
        scanf("%d",&t[i]);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        f[x][y]=f[y][x]=z;
    }
    scanf("%d",&q);
    int tot=0;
    for (int i=1; i<=q; i++)
    {
        scanf("%d%d%d",&from[i],&to[i],&day[i]);
    }
    for (int l=1; l<=q; l++)
    {
        for (int k=0; k<n; k++)
            if (t[k]<=day[l]&&!b[k])
            {
                b[k]=1;
                for (int i=0; i<n; i++)
                    for (int j=0; j<n; j++)
                        if (f[i][j]>f[i][k]+f[k][j]&&i!=j&&i!=k&&k!=j&&f[i][k]<0x7f7f7f7f&&f[k][j]<0x7f7f7f7f)
                            f[i][j]=f[i][k]+f[k][j];
            }
        if (t[from[l]]<=day[l]&&t[to[l]]<=day[l]&&f[from[l]][to[l]]!=0x7f7f7f7f)
            printf("%d\n",f[from[l]][to[l]]);
        else printf("-1\n");
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}