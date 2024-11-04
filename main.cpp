/*
//模板
#include <bits/stdc++.h>
using namespace std;
int main() {
    return 0;
}
*/
/*
#include <iostream>
int main() {
    int a;
    int b;
    std::cin >> a >> b;
    std::cout<< a <<" "<<b<<"\n";
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
*/
/*
//P5733 【深基6.例1】自动修正
#include <stdio.h>
#include <iostream>
#include <string.h>

int main() {
    char str[100];
    std::cin >> str;
    char str1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i]>='a' && str[i]<='z') {
            str1 = str[i]+'A'-'a';
            std::cout << str1;
        }
        else{
            str1 = (str[i]);
            std::cout << str1;
        }
    }
    std::cout << std::endl;
    return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main() {
    int arr[5] = {0};
    cout << "Hello World!" << '\a' << endl;
    cout << arr[0] << endl;
}
*/
/*
//P1003 [NOIP2011 提高组] 铺地毯
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    cin.ignore(100, '\n');
    int arr[n][4];
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
        cin.ignore(100, '\n');
    }
    int x,y;
    cin >> x >> y;
    int number = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i][0] <= x && x <= arr[i][0]+arr[i][2] &&
            arr[i][1] <= y && y <= arr[i][1]+arr[i][3]) {
            number = i+1;
        }
    }
    cout << number << endl;
    return 0;
}
*/
/*
//P1067 [NOIP2009 普及组] 多项式输出
#include <iostream>
using namespace std;
int main() {
    int xpow;
    cin >> xpow;
    cin.ignore(100, '\n');
    int pow;
    for (int i = xpow; i >= 0; i--) {
        cin >> pow;
        //输出加号的条件：非最高项系数、为正数
        if (i != xpow && pow >0) {
            cout << '+';
        }
        //当系数是负数的时候不需要输出负号，但系数是-1且不为常数项时只输出负号
        else if (pow == -1 && i != 0) {
            cout << '-';
        }
        else if (pow == 0){
            continue;
        }
        //接下来判断是否需要输出系数,只有当系数的绝对值不为一且不为常数项时输出
        if ((pow == 1 || pow == -1) && i != 0) {
            ;
        }
        else {
            cout << pow;
        }
        //接下来判断是否应输出x，当且仅当指数不为0时输出（系数为0时已continue）
        if (i != 0) {
            cout << 'x';
        }
        if (i == 1 || i == 0) {
            ;
        }
        else {
            cout << '^' << i;
        }
    }
    return 0;
}
*/
/*
//cpp结构体练习
#include <iostream>
using namespace std;

struct LinkList {
    int data;
    LinkList* next;
};

typedef struct LinkList LinkList;
LinkList * head = nullptr;

LinkList *Init () {
    return new LinkList;
}
int main() {
    LinkList *head = Init();
    head->data = 1;
    head->next = Init();
    head->next->data = 2;
    cout << head->data << head->next->data << endl;
    delete head;
    return 0;
}
*/
/*
//P5638 【CSGRound2】光骓者的荣耀
#include <iostream>
using namespace std;
long long int n,k;
int main() {
    cin >> n >> k;
    n--;
    long long int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long int ksum = 0;
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    if (k == 0) {
        ;
    }
    else {
        for (int i = 0; i < k; i++) {
            ksum += arr[i];
        }

        for (int i = k+1; i < n; i++) {
            if (arr[i] > arr[i-k-1]) {
                ksum += arr[i];
                ksum -= arr[i-k-1];
            }
        }
    }
    cout << sum-ksum << endl;
    return 0;
}
*/
/*
//B - Sakurako and Water
#include <iostream>
using namespace std;
void yangli() {
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    int max = 0;
    for (int i = -n+1; i < n-1; i++) {
        for (int j = 0;j<n;j++) {
            if ( 0 <= j+i && j+i < n && 0 <= j && j < n) {
                if (arr[i+j][j] < max) {
                    max = arr[i+j][j];
                }
            }
        }
        sum += -max;
        max = 0;
    }
    cout << sum << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        yangli();
    }
    return 0;
}
*/
/*
//P1421 小玉买文具
#include <iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    m+=n*10;
    cout<<m/19<<endl;
    return 0;
}
*/
/*
//P1909 [NOIP2016 普及组] 买铅笔
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[3];
    for (int & i : arr) {
        int temp1,temp2;
        cin >> temp1 >> temp2;
        if (n%temp1 == 0) {
            i = temp2*(n/temp1);
        }
        else {
            i = temp2*(n/temp1+1);
        }
    }
    sort(arr, arr+3);
    cout << arr[0] << endl;
    return 0;
}
*/
/*
//P1427 小鱼的数字游戏
#include <iostream>
using namespace std;
int main() {
    int arr[100] = {0};
    for (int &i:arr) {
        cin >> i;
        if (i == 0) {
            break;
        }
    }
    for (int i = 99; i >= 0; i--) {
        if (arr[i] == 0) {}
        else {
            cout << arr[i] << ' ';
        }
    }
    return 0;
}
*/
/*
//P1046 [NOIP2005 普及组] 陶陶摘苹果
#include <iostream>
using namespace std;
int main() {
    int arr[10];
    for (int & i : arr) {
        cin >> i;
    }
    int n;
    int sum = 0;
    cin >> n;
    n+=30;
    for (int i : arr) {
        if (i <= n) {
            sum++;
        }
        else {}
    }
    cout << sum << endl;
    return 0;
}
*/
/*
//P1014 [NOIP1999 普及组] Cantor 表
#include <iostream>
using namespace std;
int N;
int main() {
    cin >> N;
    int num = 0;
    while (1) {
        if (N <= num) {
            break;
        }
        else {
            N -= num;
            num++;
        }
    }
    if (num%2 == 0) {
        num-=N;
        cout << N << '/' << num+1;
    }
    else {
        num-=N;
        cout << num+1 << '/' << N;
    }
    return 0;
}
*/
/*
//P1055 [NOIP2008 普及组] ISBN 号码
#include <iostream>
using namespace std;
int main() {
    char arr[14];
    cin >> arr;
    int ji = 0;
    int he = 1;
    for (int i = 0; i < 12; i++) {
        if (arr[i] == '\0' || arr[i] == '-') {
            continue;
        }
        else {
            ji+=(arr[i]-'0')*he;
            he++;
        }
    }
    char aa = (char)(ji%11 + '0' );
    if (aa == arr[12]) {
        cout << "Right" << endl;
    }
    else if (aa == ':' && arr[12] == 'X') {
        cout << "Right" << endl;
    }
    else if (aa == ':') {
        arr[12] = 'X';
        cout << arr << endl;
    }
    else {
        arr[12] = aa;
        cout << arr << endl;
    }
    return 0;
}
*/
/*
//P9741 「KDOI-06-J」翻转与反转
//时间复杂度太大
#include <iostream>
using namespace std;
int n;
void one(unsigned int *p,int i) {
    for (unsigned int j=0;j<i/2;j++) {
        swap(p[j],p[i-1-j]);
    }
}

void two(unsigned int *p,int i) {
    for (unsigned int j=0;j<i;j++) {
        p[j] = p[j] ^ 0b0000000000000001;
    }
}
int main() {
    cin >> n;
    unsigned int a[n];
    for (int i = 0; i<n;i++) {
        cin >> a[i];
    }
    for (int i = 1; i<=n;i++) {
        one (a,i);
        two (a,i);
    }
    for (unsigned int &i:a) {
        cout << i << ' ';
    }
    return 0;
}
*/
/*
//测试用，无用代码
#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    int arr[n] = {0};
    for (int &i : arr) {
        cout << i << ' ';
    }
    return 0;
}
*/
/*
//P1838 三子棋I
#include <iostream>
using namespace std;
int main() {
    string shu;
    cin >> shu;
    int chess[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            chess[i][j] = -1;
        }
    }
    for (int i = 0; i < 9; i+=2) {
        if (shu[i] != '\0') {
            chess[(shu[i]-'1')/3][(shu[i]-'1')%3] = 0;
        }
        else {break;}
        if (shu[i+1] != '\0') {
            chess[(shu[i+1]-'1')/3][(shu[i+1]-'1')%3] = 1;
        }
        else {break;}
    }

    for (int i = 0; i < 3; i++) {
        if (chess[i][0] == 0 && chess[i][1] == 0 && chess[i][2] == 0) {
            cout << "xiaoa wins." << endl;
            return 0;
        }
        if (chess[0][i] == 0 && chess[1][i] == 0 && chess[2][i] == 0) {
            cout << "xiaoa wins." << endl;
            return 0;
        }
    }
    for (int i = 0; i < 1; i++) {
        if (chess[0][0] == 0 && chess[1][1] == 0 && chess[2][2] == 0) {
            cout << "xiaoa wins." << endl;
            return 0;
        }
        if (chess[0][2] == 0 && chess[1][1] == 0 && chess[2][0] == 0) {
            cout << "xiaoa wins." << endl;
            return 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (chess[i][0] == 1 && chess[i][1] == 1 && chess[i][2] == 1) {
            cout << "uim wins." << endl;
            return 0;
        }
        if (chess[0][i] == 1 && chess[1][i] == 1 && chess[2][i] == 1) {
            cout << "uim wins." << endl;
            return 0;
        }
    }
    for (int i = 0; i < 1; i++) {
        if (chess[0][0] == 1 && chess[1][1] == 1 && chess[2][2] == 1) {
            cout << "uim wins." << endl;
            return 0;
        }
        if (chess[0][2] == 1 && chess[1][1] == 1 && chess[2][0] == 1) {
            cout << "uim wins." << endl;
            return 0;
        }
    }
    cout << "drew." << endl;
    return 0;
}
*/
/*
//随便写的，无意义
#include <iostream>
using namespace std;
int main() {
    system("chcp 65001");
    int days;
    cin >> days;
    if (days <=20) {
        cout << "应发工资2000元" << endl;
    }
    else if (days <= 25) {
        cout << "应发工资" << days*100 << "元" << endl;
    }
    else {
        int wage = (days - 25) * 150 + 2500;
        cout << "应发工资" << wage << "元" <<endl;
    }
    return 0;
}
*/
/*
//A - Everyone Loves Tres
#include <iostream>
using namespace std;
void eg(int n) {
    if (n == 1 || n == 3) {
        cout << -1 << endl;
        return;
    }
    if (n == 2) {
        cout << 66 << endl;
        return;
    }
    if (n == 4) {
        cout << 3366 << endl;
        return;
    }
    if (n%2 == 0) {
        for (int i = 1; i <= n-2; i++) {
            cout << '3';
        }
        cout << "66" << endl;
        return;
    }
    else {
        for (int i = 1; i <= n-5; i++) {
            cout << '3';
        }
        cout << "36366" << endl;
        return;
    }
}
int main() {
    int t;
    cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < t; i++) {
        eg(arr[i]);
    }
    return 0;
}
*/
/*
//栈练习，将中缀表达式转换为后缀表达式
#include <iostream>
using namespace std;
char Stack[1024] = {0};
char *StackPtr = Stack;
char *StackTop = Stack;
char StackPop() {
    if (StackTop == StackPtr) {
        return -1;
    }
    *StackTop--;
    return *(StackTop+1);
}
bool StackPush(char value) {
    if (StackTop - StackPtr == 1024) {
        return false;
    }
    StackTop++;
    *StackPtr = value;
    return true;
}
void main() {
    string str;
    cin >> str;
    for (char c : str) {

    }
}
*/
/*
//P1449 后缀表达式
#include <bits/stdc++.h>
using namespace std;
char Stack[1024] = {0};
char *StackPtr = Stack;
char *StackTop = Stack;
char StackPop() {
    if (StackTop == StackPtr) {
        return -1;
    }
    *StackTop--;
    return *(StackTop+1);
}
bool StackPush(char value) {
    if (StackTop - StackPtr == 1024) {
        return false;
    }
}
*/
/*
//将中缀表达式转换为后缀表达式
char Stack[50][20];
char (*top)[20] = &Stack[0];
int numStack[50];
int *numTop = &numStack[0];
int main() {
    string str;
    //获取输入的字符串，不过似乎直接用cin >> string就行了
    cin >> str;
    int i = 0;
    for (char c : str) {
        if (c == '@') {
            (*top)[i] = '@';
            break;
        }
        if (c == '.') {
            int tempnum = 0;
            for (int j = 0; j <= i;j++) {
                tempnum += ((*top)[j]-'0')*pow(10,i-1);
            }
            i = 0;
            top++;
        }
        else {
            (*top)[i] = c;
            i++;
        }
    }
    for (auto &c : Stack) {
        if (c[0] == '@') {
            break;
        }

    }

    //cout << str << endl;
    return 0;
}
*/
/*
//P2141 [NOIP2014 普及组] 珠心算测验
#include <bits/stdc++.h>
using namespace std;
bool Found(int *arr,int sozi, const int value) {
    if (arr[sozi] < value || arr[0] > value) {
        return false;
    }
    if (arr[sozi] == value || *arr == value) {
        return true;
    }
    if (*(arr+sozi/2) >= value) {
        return Found(arr,sozi/2,value);
    }
    else {
        return Found(arr+sozi/2,sozi/2,value);
    }
}
int main() {
    int n;

    cin >> n;
    int arr[n];
    for (int &i : arr) {
        cin >> i;
    }
    int num = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1;j < n;j++) {
            if (arr[j] == arr[i]) {
                continue;
            }
            if (Found(arr, n-1, arr[i]+arr[j]) == true) {
                num++;
                //cout << arr[i] << arr[j] << endl;
            }
        }
    }
    cout << num << endl;
    return 0;
}
*/
/*
//P2141 [NOIP2014 普及组] 珠心算测验
#include <bits/stdc++.h>
using namespace std;
bool find(int *arr,int sizo,int value) {
    if (arr[0] == value || arr[sizo] == value || arr[sizo/2] == value) {
        return true;
    }
    if (arr[0] > value || arr[sizo] < value) {
        return false;
    }
    else if (arr[sizo/2] > value){
        return find(arr,sizo/2,value);
    }
    else {
        return find(arr+sizo/2,sizo,value);
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int &i : arr) {
        cin >> i;
    }
    int num = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (i == j) {}
            else {
                if (find(arr,n-1,arr[i]+arr[j]) == true) {
                    num++;
                }
            }
        }
    }
    cout << num << endl;
    return 0;
}
*/
/*
//P1036 [NOIP2002 普及组] 选数
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
//判断是否是素数
bool isPrime(long long int n) {
    if ( n ==2 ) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    else {
        for (long long int i = 3 ;i <= sqrt(n);i+=2) {
            if (n % i == 0) {
                return false;
            }
        }
    }
    return true;
}
bool fork(ll *kk, int n2 = n-1,int k2 = k-1) {
    if (k2 == 0) {
        if (*kk == n2) {
            return false;
        }
        else {
            (*kk)++;
            return true;
        }
    }
    if (*(kk+k2) == n2) {
        if (fork(kk, n2-1,k2-1) == true) {
            kk[k2] = *(kk+k2-1)+1;
            return true;
        }
        else{
            return false;
        }
    }
    else{
        *(kk+k2) += 1;
        return true;
    }
}
int f(long long int *arr) {
    ll kk[k] = {0};
    for (int i = 0;i < k;i++) {
        kk[i] = i;
    }
    int num = 0;
    while (true) {
        ll sum = 0;
        //将从arr中选k个元素相加
        for (ll i : kk) {
            sum += arr[i];
        }
        if (isPrime(sum) == true) {
            num++;
        }
        if (fork(&kk[0]) == false) {
            return num;
        }
    }
}

int main() {
    cin>>n>>k;
    long long int arr[n];
    for (long long int &i : arr) {
        cin>>i;
    }
    int num = f(arr);
    cout << num << endl;
    return 0;
}
*/
/*
//P1048 [NOIP2005 普及组] 采药   0-1背包dp首胜，迈出学习dp的第一步
#include <bits/stdc++.h>
using namespace std;
int arr[105][2];
int dp[105][1005];
int M,T;
void ZODP() {
    for (int i = 1; i <= M; i++) {
        dp[i][0] = 0;
    }
    for (int j = 1; j <= T; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j <= T; j++) {
            if (j < arr[i-1][1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i-1][1]] + arr[i-1][0]);
            }
        }
    }
}
int main() {
    cin>> T >> M;
    for (int i = 0; i < M; i++) {
        cin >> arr[i][1] >> arr[i][0];
    }
    ZODP();
    cout << dp[M][T] << endl;
    return 0;
}
*/
/*
//P1049 [NOIP2001 普及组] 装箱问题     还是背包dp的题，似乎有点思路了。
#include <bits/stdc++.h>
using namespace std;
int V,n;
int arr[35];
int dp[35][20005];
void ZODP() {
    for(int i=0;i<n;i++) {
        dp[i][0]=0;
    }
    for (int i = 1; i <= n ;i++) {
        for (int j = 0; j <= V; j++) {
            if (j < arr[i]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i]] + arr[i]);
            }
        }
    }
}
int main() {
    cin>>V>>n;
    arr[0] = 0;
    for (int i = 1;i<=n;i++) {
        cin>>arr[i];
    }
    ZODP();
    cout << V-dp[n][V] << endl;
}
*/
/*
//PTA ACM选拔赛7-7礼物送给你，也是01背包dp的题，趁热打铁。
#include <bits/stdc++.h>
using namespace std;
int n,c;
int arr[2010][2];
int dp[4010][2000][2];
int mindp(int i,int j) {
    if(dp[i-1][j][1] < dp[i-1][j-arr[i][0]][1] + arr[i][1]) {
        dp[i][j][1] = dp[i-1][j][1];
        dp[i][j][0] = dp[i-1][j][0];
    }
    else {
        dp[i][j][1] = dp[i-1][j-arr[i][0]][1] + arr[i][1];
        dp[i][j][0] = dp[i-1][j-arr[i][0]][0] + arr[i][0];
    }
}
void ZODP() {
    for (int i = 1; i < n*2; i++) {
        dp[i][0][0] = 0;
        dp[i][0][1] = 0;
    }
    for (int i = 1; i < c; i++) {
        dp[0][i][0] = 0;
        dp[0][i][1] = 0;
    }
    for (int i = 1; i < n*2; i++) {
        for (int j = 1 ; j < c; j++) {
            if ( j > c) {
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j][1];
            }
            else {
                if ( dp[i][j][0] < j) {
                    dp[i][j][0] = dp[i-1][j][0] + arr[i][0];
                    dp[i][j][1] = dp[i-1][j][1] + arr[i][1];
                }
                else {
                    dp[i][j][1] = min(dp[i-1][j][1], dp[i-1][j-arr[i][0]][1] + arr[i][1]);

                }
            }
        }
    }
}

int main() {
    cin>>n>>c;
    for (int i = 1; i < n*2; i+=2) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i+1][0] = arr[i][0];
        arr[i+1][1] = arr[i][1];
    }
    ZODP();
    cout << dp[n][c][1];
    return 0;
}
*/
/*
//Anya and 1100 //超时，唉
#include <bits/stdc++.h>
using namespace std;
string input;
int t;
int q;
int arr[200005][2];
int zhuangtai[1000];
int findstr(int a = 0, int b = input.length() - 3) {
    if (a<0) {
        a = 0;
    }
    if (b > input.length() - 3) {
        b = input.length() - 3;
    }
    for (int i = a; i < b; i++) {
        if (input[i] == '1' && input[i + 1] == '1' && input[i + 2] == '0' && input[i + 3] == '0') {
            return i;
        }
    }
    return -1;
}

void find(int im) {
    int der = findstr(im-3,im+4);
    if (der == -1) {
        if (zhuangtai[0] == 0) {
            cout << "NO" << endl;
        }
        else {
            for (int i = 1 ; i <= zhuangtai[0]; i++) {
                if ( im -3 < zhuangtai[i] && zhuangtai[i] < im+4) {
                    zhuangtai[i] = 0;
                }
            }
        }
    }
    else {
        for (int i = 1 ; i <= zhuangtai[0]; i++) {
            if ( im -3 < zhuangtai[i] && zhuangtai[i] < im+4) {
                zhuangtai[i] = 0;
            }
        }
        for (int i = im-3 ; i < im+4 ; i++) {
            int ba = findstr(i);
            if (ba == -1) {}
            else {
                i = ba;
                zhuangtai[zhuangtai[0]] = ba;
                zhuangtai[0]++;
            }
        }
        cout << "YES" << endl;
    }
}
void find() {
    for (int i = 0; i < input.length() - 3;i++) {
        if (input[i] == '1' && input[i + 1] == '1' && input[i + 2] == '0' && input[i + 3] == '0') {
            zhuangtai[zhuangtai[0]+1] = i;
            zhuangtai[0]++;
        }
    }
}
void EG() {
    find();
    for (int i = 0; i < q; i++) {
        input[arr[i][0]-1] = (char)(arr[i][1]+'0');
        find(i);
    }
}
int main() {
    cin >> t;
    while (t--) {
        cin >> input;
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }
        EG();
    }
    return 0;
}
*/
/*
//P2240 【深基12.例1】部分背包问题
#include <bits/stdc++.h>
using namespace std;
int N,T;
struct node {
    int m;
    int v;
} node[105];
bool sorta(struct node a,struct node b) {
    if ((double)a.v/a.m > (double)b.v/b.m) {
        return true;
    }
    return false;
}
double mun = 0;
int main() {
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> node[i].m >> node[i].v;
    }
    sort(node, node+N,sorta);
    for (int i = 0; i < N; i++) {
        if (node[i].m <= T) {
            T -= node[i].m;
            mun += node[i].v;
        }
        else {
            mun += ((double)node[i].v/node[i].m)*T;
            break;
        }
    }
    printf("%.2lf\n", mun);
    return 0;
}
*/
/*
//P1223 排队接水
#include <bits/stdc++.h>
using namespace std;
struct node {
    int i;
    int ti;
}node[1005];
int n;
bool sortcmd(struct node a,struct node b) {
    return a.ti<b.ti;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> node[i].ti;
        node[i].i = i+1;
    }
    double numtime = 0;
    sort(node,node+n,sortcmd);
    for (int i = 0; i < n; i++) {
        cout << node[i].i <<' ';
    }
    for (int i = 1; i < n ; i++) {
        numtime += node[i-1].ti * (n-i);
    }
    cout << endl;
    printf("%.2f\n",numtime/n);
    return 0;
}
*/
/*
//三战7-7 礼物送给你
#include <bits/stdc++.h>
using namespace std;
int n,c; //n是礼物数，c为目标好感度
int sumc;
int summ;
int arr[10000][2];
int dp[10000][10000];
void ZODP() {
    ; //行为只取前i个元素，列为还能丢掉的好感度值，值为丢掉礼物对应的价格之和
    int unsumc = sumc - c;
    for(int i = 0; i < n*2; i++) {
        dp[i][0] = 0;
    }
    for(int i = 1 ; i < n*2; i++) {
        for(int j = 0 ;j < sumc;j++) {
            if (j < arr[i][0]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i][0]] + arr[i][1]);
            }
        }
    }
    cout << summ - dp[n*2-1][unsumc] << endl;
}
int main() {
    cin >> n >> c;
    //假定第0个元素为提升的好感度，第1个元素为价格
    for (int i = 0; i < n*2; i+=2) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i+1][0] = arr[i][0];
        arr[i+1][1] = arr[i][1];
    } //获取输入
    sumc = 0;
    summ = 0;
    for (int i = 0; i < n*2; i++) {
        sumc += arr[i][0]; //sumc为所有礼物的总好感度
        summ += arr[i][1]; //summ为所有礼物的总花费
    }
    if (sumc < c) { //判断所有礼物是否可以加满好感度
        cout << "Error!" << endl;
        return 0;
    }
    ZODP();
    return 0;
}
*/