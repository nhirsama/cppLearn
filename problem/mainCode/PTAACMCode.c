//
// Created by zxy15 on 24-10-18.
//
/*
//本段代码是利用PTA ACM7-9题学习链表数据结构，但是在本段代码中没有考虑到变量的生命周期，导致出现悬垂指针。
#include <stdio.h>
#include <stdlib.h>
typedef long long int int64;
struct ListNode {
    int64 data;
    int64 name;
    struct ListNode *next;
};
typedef struct ListNode *List;
void initList(List P) {
    List temp = P->next;
    temp = malloc(sizeof(struct ListNode));
    P->next = temp;
    temp->data = 0;
    temp->name = 0;
    temp->next = NULL;
}
void append(List L, int64 name,int64 data) {
    while (L->next != NULL) {
        L = L->next;
    }
    if (L->next == NULL) {
        initList(L);
        L = L->next;
        L->data = data;
        L->name = name;
    }
}

//这个是PTA那个最热的游戏代码，时间复杂度和空间复杂度太高了，得用链表
int main(void) {
    int n,m;
    scanf("%d %d",&n,&m);
    int64 a[n];
    for ( int64 i=0;i<n;i++) {
        scanf("%lld",&a[i]);
    }
    int64 l[m],r[m];
    for (int64 i=0;i<m;i++) {
        scanf("%lld %lld",&l[i],&r[i]);
    }
    //此处以上为输入部分
    //Hand是一个链表的头指针，指向头元素
    struct ListNode Hand1 = {0,0,NULL};
    List Hand = &Hand1;
    //Hand初始化，指向头节点
    initList(Hand);
    for (int64 i=0;i<m;i++) {
        List p = Hand;
        for(int64 j=l[m]-1;j<r[m];j++) {
            //以下的while是为了给链表添加桶或给桶里加值
            while (p->name != a[j] & p->next != NULL) {
                p = p->next;
            }
            if (p->name == a[j]) {
                p->data++;
            }
            else {
                append(p,a[j],1);
            }
        }
        p = Hand;
        int64 datatemp = 0;
        int64 nametemp = 0;
        //遍历出最大的元素datatemp
        while (1) {
            if (p->data > datatemp) {
                datatemp = p->data;
                nametemp = p->name;
            }
            if (p->next == NULL) {
                break;
            }
            p = p->next;
        }
        printf("%lld\n",nametemp);
        Hand->next = NULL;
    }
}
*/
/*
//实在想不明白哪有问题，自己的几个用例都过了。
#include <stdio.h>
#include <stdlib.h>
typedef long long int int64;
struct LinkList {
    int64 name;
    int64 data;
    struct LinkList *next;
};
typedef struct LinkList LinkList;

LinkList* initLinkList() {
    LinkList *head = (LinkList*)malloc(sizeof(LinkList));
    head->next = NULL;
    head->name = 0;
    head->data = 0;
    return head;
}

void insertLinkList(LinkList *head, int64 name, int64 data) {
    LinkList *tempLink = head->next;
    head->next = initLinkList();
    head->next->name = name;
    head->next->data = data;
    head->next->next = tempLink;
}
void cleanLinkList(LinkList *head) {
    if (head->next == NULL) {
        free(head);
        return;
    }
    else {
        cleanLinkList(head->next);
    }
}
_Bool SortInsertLinkLint(LinkList *head, int64 name, int64 data) {

    if (head->name == name) {
        head->data++;
        return 1;
    }
    else if (head->next == NULL) {
        insertLinkList(head, name, data);
        return 1;
    }
    else if ((head->name < name) && (head->next->name > name)) {
        LinkList *tempLink = head->next;
        head->next = initLinkList();
        head->next->name = name;
        head->next->data = data;
        head->next->next = tempLink;
        return 1;
    }
    SortInsertLinkLint(head->next, name, data);
    return 0;
}
int main(void) {
    int n,m;
    scanf("%d %d",&n,&m);
    int64 a[n];
    for ( int64 i=0;i<n;i++) {
        scanf("%lld",&a[i]);
    }
    //l是最小值，从1开始，r是最大值
    int64 l[m],r[m];
    for (int64 i=0;i<m;i++) {
        scanf("%lld %lld",&l[i],&r[i]);
    }
    //此处以上为输入部分
    for (int64 i=0;i<m;i++) {
        LinkList *head = initLinkList();
        LinkList *p = head;
        for (int64 j=l[i]-1;j<r[i];j++) {
            p = head;
            SortInsertLinkLint(p,a[j],1);
        }
        //上述for用于给链表head的后续节点赋值name和data
        p = head->next;
        int64 nameTemp = 0;
        int64 dataTemp = 0;
        //下列while循环用于给出head的最大data值所对应的name值
        while(p != NULL) {
            //printf("%lld %lld\n",p->name,p->data);
            if(dataTemp < p->data) {
                dataTemp = p->data;
                nameTemp = p->name;
            }
            p = p->next;
        }
        printf("%I64d\n",nameTemp);
        cleanLinkList(head);
    }
    return 0;
}
*/
/*
//洛谷函数与结构体题单，P5735
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
double 周长(double *x,double *y) {
    double d12s,d13s,d23s;
    d12s=sqrt(pow(x[1]-x[0],2)+pow(y[1]-y[0],2));
    d13s=sqrt(pow(x[1]-x[2],2)+pow(y[1]-y[2],2));
    d23s=sqrt(pow(x[2]-x[0],2)+pow(y[2]-y[0],2));
    return d12s+d13s+d23s;
}
int main(void) {
    double x[3],y[3];
    for(int i = 0; i < 3; i++) {
        scanf("%lf %lf",&x[i],&y[i]);
    }
    printf("%.2lf\n",周长(x,y));

*/
/*
//洛谷P5736 【深基7.例2】质数筛，主要是判断质数需要了解一些东西
#include <stdio.h>
int 是否是素数(int N) {
    if (N <= 1) {
        return 0;
    }
    for (int i = 2;i*i <= N;i++) {
        if (N % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int N;
    scanf("%d",&N);
    int a[N];
    for (int i = 0;i < N;i++) {
        scanf("%d",&a[i]);
    }
    for (int i = 0;i < N;i++) {
        if (是否是素数(a[i]) == 1) {
            printf("%d ",a[i]);
        }
    }
}
*/
/*
//洛谷打印一个合数的最大质因数的题
#include <stdio.h>
#include <math.h>
typedef long long int int64;
_Bool 是否是素数(int64 N) {
    if (N <= 1) {
        return 0;
    }
    for (int64 i = 2;i*i <= N;i++) {
        if (N % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int64 N;
    scanf("%lld",&N);
    for (int64 i= 2;i <= sqrt(N);i++) {
        if(是否是素数(i) == 1) {
            if(N % i == 0) {
                printf("%lld\n",N/i);
            }
        }
    }
}
*/
/*
//洛谷P1304 哥德巴赫猜想
#include <stdio.h>
typedef long long int int64;
_Bool 是否是素数(int64 N) {
    if (N <= 1) {
        return 0;
    }
    for (int64 i = 2;i*i <= N;i++) {
        if (N % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int64 N;
    scanf("%lld",&N);
    for (int64 m = 2;m <= N;m+=2) {
        for (int64 i = 2;i <= m;i++) {
            if (是否是素数(i) == 1) {
                if(是否是素数(m-i) == 1) {
                    printf("%lld=%lld+%lld\n",m,i,m-i);
                    break;
                }
            }
        }
    }
}
*/
/*
//洛谷P2089烤鸡
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n<10) {
        printf("0");
        return 0;
    }
    if (n>30) {
        printf("0");
        return 0;
    }

}
*/
/*
//洛谷P1042 [NOIP2003 普及组] 乒乓球
//6：5的情况是不会结束比赛的，还会往后顺延直至某一方取得胜利
#include <stdio.h>
int main() {
    char arr[25*2502];
    for (int i = 0; arr[i-1] != 'E' ; i++) {
        scanf("%c", &arr[i]);
    }
    int jishu = 0;
    int jia = 0,yi = 0;
    for (int i = 0; arr[i] != 'E' ; i++) {
        if (jishu == 11) {
            jishu = 0;
            printf("%d:%d\n", jia,yi);
            jia = 0;
            yi = 0;
        }
        switch (arr[i]) {
            case 'W': {
                jia++;
                jishu++;
                continue;
            }
            case 'L': {
                yi++;
                jishu++;
                continue;
            }
        }
    }
    printf("%d:%d\n", jia,yi);
    if (jishu == 11) {
        printf("0:0\n");
    }
    printf("\n");
    jishu = 0;
    jia = 0;
    yi = 0;
    for (int i = 0; arr[i] != 'E' ; i++) {
        if (jishu == 21) {
            jishu = 0;
            printf("%d:%d\n", jia,yi);
            jia = 0;
            yi = 0;
        }
        switch (arr[i]) {
            case 'W': {
                jia++;
                jishu++;
                continue;
            }
            case 'L': {
                yi++;
                jishu++;
                continue;
            }
        }
    }
    printf("%d:%d\n", jia,yi);
    if (jishu == 21) {
        printf("0:0\n");
    }
    return 0;
}
*/
/*
//P1009 [NOIP1998 普及组] 阶乘之和
#include <stdio.h>
typedef __int128 int64;
int64 jiecheng(int64 n) {
    if (n == 1) return 1;
    return n*jiecheng(n-1);
}
int main() {
    int64 n=0;
    scanf("%lld",&n);
    int64 sum = 0;
    for (int i=1;i<=n;i++) {
        sum+=jiecheng(i);
    }
    long long int *aa = (long long int*)&sum;
    if (*(aa+1) != 0) {
        printf("%lld",*(aa+1));
    }
    printf("%llu\n",*aa);
    return 0;
}
*/
/*
//P1401 [入门赛 #18] 禁止在 int 乘 int 时不开 long long
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
/*
int main(void) {
    long long int xmax,xmin;
    long long int ymax,ymin;
    scanf("%lld %lld %lld %lld",&xmin,&xmax,&ymin,&ymax);
    if(xmin<0 && (-xmin)>xmax) {
        xmax = -xmin;
    }
    if(ymin<0 && (-ymin)>ymax) {
        ymax = -ymin;
    }
    if(ymax*xmax>=(pow(2,31))){
        printf("long long int");
    }
    else {
        printf("int");
    }
    return 0;
}
*/
/*
//这样例是真恶心，上面的那段代码一直有一个不过，被迫穷举
int main(void) {
    long long int xmax,xmin;
    long long int ymax,ymin;
    scanf("%lld %lld %lld %lld",&xmin,&xmax,&ymin,&ymax);
    if(xmax*ymin <= pow(2,31)-1 &&
        xmax*ymin >= -pow(2,31) &&
        ymax*xmin <= pow(2,31)-1 &&
        ymax*xmin >= -pow(2,31) &&
        xmin*ymin <= (pow(2,31)-1) &&
        xmin*ymin >= -pow(2,31) &&
        ymax*xmax <= pow(2,31)-1 &&
        ymax*xmax >= -pow(2,31)) {
            printf("int\n");

    }
    else {
        printf("long long int\n");
    }
    return 0;
}
*/
/*
//P1307 [NOIP2011 普及组] 数字反转
#include <stdio.h>
int main() {
    char arr[13];
    for (int i = 0; i < 13; i++) {
        arr[i] = '\0';
    }
    scanf("%s", arr);
    if(arr[0] == '-') {
        printf("-");
    }
    int m = 0;
    for(int i = 0; i < 13; i++) {
        ++m;
        if(arr[i] == '\0') {
            break;
        }
    }
    int farst0 = 0;
    for(int i = m-2; i >= 0; i--) {
        if(arr[i] == '-') {
            continue;
        }
        if(farst0 == 0 && arr[i] == '0') {
            continue;
        }
        farst0 = 1;
        printf("%c", arr[i]);
    }
    if(farst0 == 0) {
        printf("0");
    }
    printf("\n");
    return 0;
}
*/

/*
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
*/