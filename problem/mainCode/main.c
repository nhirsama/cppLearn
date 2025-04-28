#include <stdio.h>
/************************************************************************/
/*   用于交换两个字符串
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main() {
    int a = 3, b = 4;
    swap(&a, &b);
    printf("a=%d,b=%d\n", a, b);
}
*/
/************************************************************************/

/************************************************************************/
/*
char findTheDifference(char* s, char* t) {
    int sums =0;
    int sumt =0;
    int len = 0;
    char*a = s;
    while (*a++ != '\0') {      //这个循环用以检测指针a所指字符串的长度
        len++;
    }
    char sis = len;

    for(char i = 0; i < sis; i++)
    {
        sums=sums+(*s);
        sumt=sumt+(*t);
        s++;t++;
    }
    sumt=sumt+(*(t));
    return sumt-sums;
}


int main() {
    char s[] = "HelloWorld";
    char t[] = "HelloWorlda";
    printf("%c\n", findTheDifference(s, t));
}
*/
/************************************************************************/

/************************************************************************/
/*    力扣28题
int strStr(char* haystack, char* needle) {
    int down = 0;
    char* rest = needle;
    char* rest2 = haystack;
    char* rest3 = haystack;
    int down2 = -1;
    while(*haystack != '\0'){

        if(*haystack == *needle)
        {
            if(down2 == -1){
                down2 = rest2-rest3;
                rest2 = haystack;
            }
            if(*(needle+1) == '\0'){
                return down2;
            }
            haystack++;
            needle++;
        }
        else{
            needle = rest;
            down2 = -1;
            haystack = rest2;
            haystack++;
            rest2++;
        }

        down++;
    }
    return -1;
}


int main() {
    char haystack1[]="mississippi";
    char needle1[]="pi";
    char *needle = &needle1;
    char *haystack = &haystack1;
    printf("%d",strStr(haystack,needle));
    return 0;
}
*/
/************************************************************************/

/************************************************************************/
// 本用于检测两个字符串是否互为乱序，但是ac、bb之类的测试无法通过
/*
bool isAnagram(char* s, char* t) {
    int lens = 0;
    int lent = 0;
    while(*s != '\0'){
        lens = lens+(*s);
        lent = lent+(*t);
        s++;t++;
        if((*s == '\0') ^ (*t == '\0')){
            return 0;
        }

    }
    return !(lens-lent);
}

int main() {
    char s1[]="a";
    char t1[]="ab";
    char *s = &s1;
    char *t = &t1;
    printf("%d\n",isAnagram(s,t));
    return 0;
}
*/
/************************************************************************/

/************************************************************************/
/*
int arraySign(int* nums, int numsSize) {
    int and = 2147483647;
    for (int i = 0; i < numsSize; i++) {
        and = and^*nums;
        if (*nums == 0) {
            return 0;
        }
        nums++;
    }
    if (and < 0) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    int nums[10] = {1,5,0,2,-3};
    int numsSize = 10;
    int *nums1 = &nums[0];
    printf("%d\n", arraySign(nums, numsSize));
    return 0;
}
*/
/************************************************************************/

/************************************************************************/
/*      //冒泡排序失败写法
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void canMakeArithmeticProgression(int* arr, int arrSize) {
    int i = 0;
    while(i < arrSize){
        if(*(arr+i)>*(arr+i+1)){
            swap(arr,arr+1);
            i = 0;
        }
        i++;
    }
}

int main() {
    int arr[10] = {13,72,3,3,25,61,72,88,9,10};
    canMakeArithmeticProgression(arr,10);
    printf("%d",*arr);
}


*/
/************************************************************************/


/************************************************************************/
/*
# 超级玛丽游戏

## 题目背景

本题是洛谷的试机题目，可以帮助了解洛谷的使用。

建议完成本题目后继续尝试 [P1001](/problem/P1001)、[P1008](/problem/P1008)。

另外强烈推荐[新用户必读贴](/discuss/show/241461)

## 题目描述

超级玛丽是一个非常经典的游戏。请你用字符画的形式输出超级玛丽中的一个场景。

```

               ************
               ####....#.
             #..###.....##....
             ###.......######              ###            ###
                ...........               #...#          #...#
               ##*#######                 #.#.#          #.#.#
            ####*******######             #.#.#          #.#.#
           ...#***.****.*###....          #...#          #...#
           ....**********##.....           ###            ###
           ....****    *****....
             ####        ####
           ######        ######
##############################################################
#...#......#.##...#......#.##...#......#.##------------------#
###########################################------------------#
#..#....#....##..#....#....##..#....#....#####################
##########################################    #----------#
#.....#......##.....#......##.....#......#    #----------#
##########################################    #----------#
#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#
##########################################    ############
```
*/
/*
int main() {
    printf("                ********\n");
    printf("               ************\n");
    printf("               ####....#.\n");
    printf("             #..###.....##....\n");
    printf("             ###.......######              ###            ###\n");
    printf("                ...........               #...#          #...#\n");
    printf("               ##*#######                 #.#.#          #.#.#\n");
    printf("            ####*******######             #.#.#          #.#.#\n");
    printf("           ...#***.****.*###....          #...#          #...#\n");
    printf("           ....**********##.....           ###            ###\n");
    printf("           ....****    *****....\n");
    printf("             ####        ####\n");
    printf("           ######        ######\n");
    printf("##############################################################\n");
    printf("#...#......#.##...#......#.##...#......#.##------------------#\n");
    printf("###########################################------------------#\n");
    printf("#..#....#....##..#....#....##..#....#....#####################\n");
    printf("##########################################    #----------#\n");
    printf("#.....#......##.....#......##.....#......#    #----------#\n");
    printf("##########################################    #----------#\n");
    printf("##########################################    ############\n");
    return 0;
}
*/
/************************************************************************/


/************************************************************************/
/*
# A+B Problem

## 题目背景

强烈推荐[新用户必读帖](/discuss/show/241461)。

**不熟悉算法竞赛的选手请看这里：**

算法竞赛中要求的输出格式中，**不能有多余的内容**，**这也包括了“请输入整数 $\bm a$ 和 $\bm b$” 这一类的提示用户输入信息的内容**。若包含了这些内容，将会被认为是 `Wrong Answer`，即洛谷上的 `WA`。在对比代码输出和标准输出时，系统将忽略每一行结尾的空格，以及最后一行之后多余的换行符。

若因此类问题出现本机似乎输出了正确的结果，但是实际提交结果为错误的现象，请勿认为是洛谷评测机出了问题，而是你的代码中可能存在多余的输出信息。用户可以参考在题目末尾提供的代码。

此外，**请善用应用中的在线 IDE 功能**，以避免不同平台的评测产生差异。

最后，请不要在对应的题目讨论区中发布自己的题解，请发布到题解区域中，否则将处以删除或禁言的处罚。若发现无法提交题解则表明本题题解数量过多，仍不应发布讨论。若您的做法确实与其他所有题解均不一样，请联系管理员添加题解。

## 题目描述

输入两个整数 $a, b$，输出它们的和（$|a|,|b| \le {10}^9$）。

注意

1. Pascal 使用 `integer` 会爆掉哦！
2. 有负数哦！
3. C/C++ 的 main 函数必须是 `int` 类型，而且 C 最后要 `return 0`。这不仅对洛谷其他题目有效，而且也是 NOIP/CSP/NOI 比赛的要求！

好吧，同志们，我们就从这一题开始，向着大牛的路进发。

> 任何一个伟大的思想，都有一个微不足道的开始。

## 输入格式

两个以空格分开的整数。

## 输出格式

一个整数。

## 样例 #1

### 样例输入 #1

```
20 30
```

### 样例输出 #1

```
50
```
*/
/*
int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",a+b);
    return 0;
}

*/
/************************************************************************/


/************************************************************************/
/*      //超时，没法用
float tiaohe(int n,double sn){
    if(n<=1) {return 1;}
    return 1.0/n+tiaohe(n-1,sn);
}

int main() {
    int k;
    int n = 1;
    scanf("%d",&k);
    while(k >= tiaohe(n,0.0)) {
        n++;
    }
    printf("%d\n",n);
    return 0;
}
*/
/************************************************************************/


/************************************************************************/
/*      //洛谷入门第二题
int main() {
    int k,n=0;
    scanf("%d",&k);
    for(double sn=0;k>=sn;n++,sn=sn+1.0/n){}
    printf("%d",n);
    return 0;
}

*/
/************************************************************************/


/************************************************************************/
/*      //洛谷P1152 欢乐的跳，还挺简单的
int jveduizhi(int shu) {
    if (shu < 0){return -shu;}
    return shu;
}

int main() {
    long long n;
    scanf("%lld",&n);
    int arr[n];
    int arrcha[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        arrcha[i] = 0;
    }
    arrcha[0]=1;
    for(int i=0;i<n-1;i++) {
        int aaa = jveduizhi(arr[i+1]-arr[i]);
        if(aaa>n) {
            printf("Not jolly");
            return 0;
        }
        arrcha[aaa] = 1;
    }
    for(int i=1;i<=n-1;i++) {
        if(arrcha[i]==1) {
            if(i == n-1) {
                printf("Jolly");
                return 0;
            }
        }
        else if(arrcha[i]==0) {
            printf("Not jolly");
            return 0;
        }
    }
}
*/
/************************************************************************/


/************************************************************************/
#include <math.h>
#include <stdio.h>
/*
        //ACM校内预选赛7-5，纯纯傻卵题，用二分法挺好写，但是存在一题多解和输出顺序问题。

#define int32 long long int
int32 xminmax(int32 *xmin, int32 *xmax, int32 *ymin, int32 *ymax,int32 *zmin, int32 *zmax,int32 n) {
    int32 y = *ymin;
    int32 z = *zmin;
    while (1) {
        int32 x = (*xmin+*xmax)/2;
        if(*xmax - *xmin <= 1000) {
            return 1;
        }
        else {
            if(n < 2*(x*y*z/(x*y+x*z+y*z))){
                *xmax = x;
            }
            else {
                *xmin = x;
            }
        }
    }
}
int32 yminmax(int32 *xmin, int32 *xmax, int32 *ymin, int32 *ymax,int32 *zmin, int32 *zmax,int32 n) {
    int32 x = *xmin;
    int32 z = *zmin;
    while (1) {
        int32 y = (*ymin+*ymax)/2;
        if(*ymax - *ymin <= 1000) {
            return 1;
        }
        else {
            if(n < 2*(x*y*z/(x*y+x*z+y*z))){
                *ymax = y;
            }
            else {
                *ymin = y;
            }
        }
    }

}
int32 zminmax(int32 *xmin, int32 *xmax, int32 *ymin, int32 *ymax,int32 *zmin, int32 *zmax,int32 n) {
    int32 x = *xmin;
    int32 y = *ymin;
    while (1) {
        int32 z = (*zmin+*zmax)/2;
        if(*zmax - *zmin <= 1000) {
            return 1;
        }
        else {
            if(n < 2*(x*y*z/(x*y+x*z+y*z))){
                *zmax = z;
            }
            else {
                *zmin = z;
            }
        }
    }
}

int main() {
    int32 n;
    scanf("%lld",&n);
    int32 arr[] = {1,20000,1,20000,1,20000};
    int32 *arrto = &arr;
    xminmax(arrto,arrto+1,arrto+2,arrto+3,arrto+4,arrto+5,n);
    yminmax(arrto,arrto+1,arrto+2,arrto+3,arrto+4,arrto+5,n);
    zminmax(arrto,arrto+1,arrto+2,arrto+3,arrto+4,arrto+5,n);
    for(int x = arr[0];x <=arr[1];x++) {
        for(int y = arr[2]; y <= arr[3]; y++) {
            for(int z = arr[4]; z <= arr[5]; z++) {
                if(n == 2*x*y*z/(x*y+x*z+y*z)){
                    printf("%d %d %d\n",x,y,z);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
 }

*/
/************************************************************************/


/************************************************************************/
/*      //最烦的就是过了一半测试点，另一半没过，想不明白为什么。
#include <stdio.h>
// int main(int) {
//     int t;
//     scanf("%d",&t);
//     int zhan1[t],zhan2[t];
//     int *zhan1to = &zhan1[0];
//     int *zhan2to = &zhan2[0];
//     while(t--) {
//         scanf("%d %d",zhan1to,zhan2to);
//         zhan1to++;
//         zhan2to++;
//     }
//     while(t--) {
//         int yvshu[*zhan1to];
//         int temp = *zhan1to;
//         while((*zhan1to)--)
//         {
//             yvshu[*zhan1to] = *zhan1to%3;
//             *zhan2to = *zhan2to /3;
//         }
//         int num;
//         while(temp--)
//         {
//
//             if(yvshu[temp]==1)
//             {
//
//             }
//             else if(yvshu[temp]==2 & yvshu[temp]==0)
//             {
//                 num = num*2;
//             }
//         }
//         printf("%d",num%998244353);
//     }
//     return 0;
// }
*/
/*
#include <stdio.h>
int main(int) {
    int t;
    scanf("%d",&t);
    int zhan1[t],zhan2[t];
    int *zhan1to = &zhan1[0];
    int *zhan2to = &zhan2[0];
    int t1 = t;
    while(t1--) {
        scanf("%d %d",zhan1to,zhan2to);
        zhan1to++;
        zhan2to++;
    }
    t1 = t;
    zhan1to = &zhan1[0];
    zhan2to = &zhan2[0];
    while(t1--) {
        int yvshu[*zhan1to];
        int temp = *zhan1to;
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
/************************************************************************/


/************************************************************************/
/*
//结构体struct学习
struct lianbiao {
    int x;
    int *next;
};
typedef struct lianbiao lianbiao;
int 顺序遍历链表(lianbiao 链表首值,int jiaobiao){
    if(链表首值.next == NULL){
        ;
    }
    else {
        return 链表首值.x;
    }
}
*/

/*
//力扣13题罗马数字转整数
int romanToInt(char* s) {
    int  toint = 0;
    for(;*s != '\0';s++) {
        if(*s == 'I' & *(s+1) == 'V') {
            toint += 4;
            s++;
            continue;
        }
        else if(*s == 'I' & *(s+1) == 'X') {
            toint += 9;
            s++;
            continue;
        }
        if(*s == 'X' & *(s+1) == 'L') {
            toint += 40;
            s++;
            continue;
        }
        else if(*s == 'X' & *(s+1) == 'C') {
            toint += 90;
            s++;
            continue;
        }
        if(*s == 'C' & *(s+1) == 'D') {
            toint += 400;
            s++;
            continue;
        }
        else if(*s == 'C' & *(s+1) == 'M') {
            toint += 900;
            s++;
            continue;
        }
        switch(*s) {
            case 'I': toint += 1;continue;
            case 'V': toint += 5;continue;
            case 'X': toint += 10;continue;
            case 'L': toint += 50;continue;
            case 'C': toint += 100;continue;
            case 'D': toint += 500;continue;
            case 'M': toint += 1000;continue;
        }
    }
    return toint;
}
int main() {
    char s[] = "MCMXCIV";
    int *sp = &s;
    printf("%d\n", romanToInt(sp));
    return 0;
}
*/

/*
//力扣一道打印时间的题，过了60%样例。
#include<stdio.h>
int main() {
    int s,v;
    scanf("%d %d",&s,&v);
    int time;
    time=s/v;
    if(s%v != 0) {
        time++;
    }
    time+=10;
    int h,m;
    h = time/60;
    m = time%60;
    if(h>=7) {
        if(m == 0) {
            printf("%d:00\n",32-h);
        }
        else if(m>50) {
            printf("%d:0%d\n",32-h,60-m);
        }
        else {
            printf("%d:%d\n",32-h,60-m);
        }
    }
    else {
        if(m == 0) {
            printf("0%d:00\n",8-h);
        }
        else if(m>50) {
            printf("0%d:0%d\n",7-h,60-m);
        }
        else {
            printf("0%d:%d\n",7-h,60-m);
        }
    }
    return 0;
}
*/
/*
//这个是PTA那个最热的游戏代码，时间复杂度和空间复杂度太高了，得用链表
int main(void) {
    int n,m;
    scanf("%d %d",&n,&m);
    long long int a[n];
    for ( long long int i=0;i<n;i++) {
        scanf("%lld",&a[i]);
    }
    long long int l[m],r[m];
    for (long long int i=0;i<m;i++) {
        scanf("%lld %lld",&l[i],&r[i]);
    }
    //此处以上为输入部分
     long long int temp = 0;
    for (long long int i=0;i<n;i++) {
        if(a[i]>temp) {
            temp=a[i];
        }
    }
    for (long long int i=0;i<m;i++) {
        long long int max = 0;
        long long int tong[temp+1];
        for(long long int w=0;w<temp+1;w++) {
            tong[w]=0;
        }
        for(long long int j=l[i]-1;j<r[i];j++) {
            tong[a[j]]+=1;
        }
        long long int listdown = 0;
        long long int k = 0;
        for(;k<(temp+1);k++) {
            if(tong[k]>max) {
                max = tong[k];
                listdown = k;
            }
        }
        printf("%lld\n",listdown);
    }
}
*/
/*
//时间复杂度o(1)的算法，如果在考试的时候能想到就直接秒杀了
#define llint long long int
int main(void) {
    llint n;
    scanf("%lld",&n);
    llint x,y,z;
    x = n;
    y = n+1;
    z = n*(n+1);
    if(n == 1)
        printf("-1");
    else if(2*x*y*z == n*(x*y+x*z+y*z))
        printf("%lld %lld %lld\n",x,y,z);
    return 0;
}
*/
/*
//练习结构体写法的，但是写的不怎么样
#define llint long long int
typedef struct status {
    llint name;
    llint data;
    struct status *next;
}status;
status* initstatus(llint name, llint data,status *next) {
    status new = {name, data, next};
 return &new;
}
void ChaRustatus(status *LineList,llint name,llint data) {
    status *number = LineList;
    if(number->next==NULL) {
        number->next = initstatus(name,data,NULL);
    }
    else {
        llint nametemp = LineList->name;
        llint datatemp = LineList->data;
        status *nexttemp = LineList->next;
        LineList->data = data;
        LineList->name = name;
        LineList->next = nexttemp;
        initstatus(nametemp,datatemp,nexttemp);
    }
}

int main() {
    status *LineList = initstatus(5,2,NULL);
    printf("%lld %lld\n",LineList->name,LineList->data);
    return 0;
}
*/
/*
// PTA，ACM选拔赛7-3
int main(void) {
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[m];
    for(int i=0;i<m;i++) {
        scanf("%d",&arr[i]);
    }
    int buchang = 1;
    int weizhi = 1;
    for(int i=0;i<m;i++) {
        if(arr[i] == 1) {
            if(buchang+weizhi > n)
                weizhi = buchang +weizhi -n;
            else
                weizhi = buchang+weizhi;
        }
        else if(arr[i] == 2) {
            buchang+=1;
        }
        else
            printf("%d\n",weizhi);
    }
    return 0;
}
*/
#include <stdio.h>
/*
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