#include <cstdio>
#include <cstring>
const int S=303;//一次加法顶多多一位，所以顶多多30位，也就是130位左右。我开大一点，开到300.
int n,a[S],l;
char c[S],d[S];
inline void add()
{
    for (int i=0;i<l;++i)
        d[l-i-1]=c[i];
    l+=2;//可能有进位，所以我们干脆在前面先多空个两位
    for (int i=0;i<l;++i)
    {
        c[i]+=d[i];
        if (c[i]>=n) c[i+1]++,c[i]-=n;
    }
    while (!c[l-1]) --l;//大不了多余的前导0再减回来嘛~~简化思维~~
}
inline bool pd()
{
    for (int i=0;i<l;++i)
        if (c[i]!=c[l-1-i]) return false;
    return true;
}
int main()
{
    scanf("%d%s",&n,c);l=strlen(c);
    for (int i=0;i<l;++i)
    {
        if (c[i]>='0' && c[i]<='9') c[i]-='0';
        else c[i]=c[i]-'A'+10;
    }
    int step=0;
    while (!pd())
    {
        ++step;
        if (step>30) break;
        add();
    }
    if (step<=30) printf("STEP=%d\n",step);
    else puts("Impossible!");
    return 0;
}