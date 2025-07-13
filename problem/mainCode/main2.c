/*
 //测试用例都通过了，把ing都改成long long int就行了
int main(int) {
    long long int t;
    scanf("%lld",&t);
    long long int zhan1[t],zhan2[t];
    long long int *zhan1to = &zhan1[0];
    long long int *zhan2to = &zhan2[0];
    long long int t1 = t;
    while(t1--) {
        scanf("%lld %lld",zhan1to,zhan2to);
        zhan1to++;
        zhan2to++;
    }
    t1 = t;
    zhan1to = &zhan1[0];
    zhan2to = &zhan2[0];
    while(t1--) {
        long long int yvshu[*zhan1to];
        long long int temp = *zhan1to;
        while((*zhan1to)--)
        {
            yvshu[*zhan1to] = (*zhan2to)%3;
            if (yvshu[*zhan1to] == 0) {
                *zhan2to = *zhan2to/3;
            }
            else {
                *zhan2to = (*zhan2to/3) +1;
            }
        }
        long long int num = 1;
        while(temp--)
        {

            if(yvshu[temp]==1 | yvshu[temp]==0)
            {
                num = num*2;
            }
            else if(yvshu[temp]==2)
            {

            }
        }
        num = num/2;
        printf("%lld\n",num%998244353);
        zhan1to++;
        zhan2to++;
    }
    return 0;
}
*/
/*
 //求阶乘的一个算法，意义不大
int main(void)
{
    long long int n;
    scanf("%lld",&n);
    long long int sum = 1;
    for(int i=1;i<=n;i++)
    {
        sum = sum * i;
    }
    printf("%lld\n",sum-1);
}
*/
/*
int max( long long int *list)
{
    long long int maxv;
    maxv = *list;
    for(;*list == '\0';list++);
    {
        if (*list >= maxv)
        {
            maxv = *list;
        }
    }
    return maxv;
}
int main(void)
{
    long long int n,m;
    scanf("%lld %lld",&n,&m);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    long long int l[m];
    long long int r[m];
    for(int i=0;i<m;i++)
    scanf("%d %d",&l[i],&r[i]);
    int listlen = max(&a);
    for(int i=0;i<m-1;i++)
    {
        long long int tong[listlen];
        for(int j=0;j<listlen;j++)
        {
            tong[j]=0;
        };
        for(int j = l[i]-1;j<r[i]-1;j++)
        {
            tong[j] +=1;
        }
        for(int k = 0;k<listlen;k++)
        {
            int downlist;
            long long int maxv = 0;
            if (tong[k] >= maxv)
            {
                maxv = tong[k];
                 downlist= k;
            }

            printf("%d\n",downlist);
        }
    }
    return 0;
}
*/
/*
//HUE ACM集训第二次训练
//C题
#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    int arr[N*N];
    for(int i=0;i<N*N;i++)
    {
        arr[i]=0;
    }
    int sum=0;
    for(int i=0;i<N*N;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
        if(sum>=N*N)
        {
            break;
        }
    }
    int hang = 0;
    for(int i =0;i<N*N;i++)
    {
        if(arr[i] == 0 && arr[i+1] == 0){break;}
        if(i%2 == 0)
        {
            for(int j=0;j<arr[i];j++)
            {
                printf("0");
                hang++;
                if(hang >= N){printf("\n");hang = 0;}
            }
        }
        if(i%2 == 1){
            for(int j=0;j<arr[i];j++)
            {
                printf("1");
                hang++;
                if(hang >= N){printf("\n");hang = 0;}
            }
        }
    }
}
*/
/*
//HUE ACM第二次集训B题
#include <math.h>
#include <stdio.h>
//找出输入数组n的中位数并使其与数组n的平均数做差，得到的值乘以n则是输出的x；
int 冒泡排序(int arr[],int lenarr)
{
    int i, j, temp;
    for (i = 0; i < lenarr - 1; i++) {
        for (j = 0; j < lenarr - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int 计算x的值(int arr[],int lenarr)
{

}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    冒泡排序(a,n);
    int junzhi = 0;
    if (n%2 == 0)
    {
        junzhi = (float)(a[n/2-1]+a[n/2]);
        junzhi = junzhi/2;
    }
    if (n%2 == 1)
    {
        junzhi = (float)(a[(n-1)/2])/2;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=a[i];
    }
    sum = (float)sum/n;
    float x = sum/2-junzhi;
    printf("%.2f",x);
    return 0;

}
*/
/*
#include <stdio.h>
#include <stdlib.h>
struct LinkList
{
    struct LinkList *next;
    int number;
    int data;
};
typedef struct LinkList LinkList;
LinkList* InitLinkList()
{
    LinkList *Temp = (LinkList*)malloc(sizeof(LinkList));
    Temp->next = NULL;
    Temp->number = 0;
    Temp->data = 0;
    return Temp;
};
void Swap(LinkList* a, LinkList* b)
{
    LinkList *Temp;
    Temp = a->next;
    a->next = b->next;
    b->next = Temp;
}
void DelLinkList(LinkList* head)
{
    if (head->next == NULL)
    {
        free(head);
    }
    else
    {
        LinkList *Temp = head->next;
        free(head);
        DelLinkList(Temp);
    }
}
LinkList* Found(LinkList* head,int number)
{
    if (head->next == NULL)
    {
        return NULL;
    }
    if (head->number == number)
    {
        return head;
    }
    Found(head->next,number);
}
int main()
{
    LinkList* Head = InitLinkList();
    int n,m;
    scanf("%d %d", &n,&m);
    LinkList* Temp = Head;
    for (int i = 0; i < n+1; i++)
    {
        Temp->next = InitLinkList();
        Temp->number = i;
        Temp = Temp->next;
    }
    int numtemp;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &numtemp);
        Found(Head,numtemp)->data++;
    }
    Temp = Head->next;
    for (int i = 1; i < n+1; i++)
    {
        int aaa = Temp->data;
        for (int j = 0; j < aaa; j++)
        {
            printf("%d ",i);
        }
        Temp=Temp->next;
    }
    DelLinkList(Head);
    return 0;
}
*/
/*
//这是我学习Cpp语法的契机，c的输入输出可能有些问题。
#include <stdio.h>
int main()
{
    int arr[3];
    char arr1[3];

    scanf("%d", &arr[0]);
    scanf("%s", arr1);
    //scanf("%c %c %c", &arr1[0], &arr1[1], &arr1[2]);
    int temp;
    for (int i = 3; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        switch (arr1[i])
        {
            case 'A':printf("%d ",arr[0]);continue;
            case 'B':printf("%d ",arr[1]);continue;
            case 'C':printf("%d",arr[2]);continue;
        }
    }
    return 0;
}
*/