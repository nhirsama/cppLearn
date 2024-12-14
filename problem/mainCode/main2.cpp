/*
//模板
#include <bits/stdc++.h>
using namespace std;
int main() {
    return 0;
}
*/
/*
//P1020 [NOIP1999 提高组] 导弹拦截
#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int nLength;

int input();

int main() {
    nLength = input();

    return 0;
}

int input() {
    int n = 0;
    while (cin.peek() != '\0') {
        cin >> arr[n++];
    }
    return n+1;
}

int DP() {

}
*/
/*
//P1011 [NOIP1998 提高组] 车站
#include <bits/stdc++.h>
using namespace std;
int Fib[23];
int a,n,m,x;
int People[23][2];
void fib();
int main() {
    fib();
    cin >> a >> n >> m >> x;
    if (n == 2 || n == 1 || n == 3) {
        cout << a << endl;
        return 0;
    }
    People[1][0] = 1;
    People[2][0] = 1;
    People[3][0] = 2;
    for (int i = 4; i <= n; i++) {
        People[i][0] = People[i-1][0] + Fib[i-2] - Fib[i-3];
        People[i][1] = People[i-1][1] + Fib[i-1] - Fib[i-2];
    }
    int y = (m-People[n-1][0]*a)/People[n-1][1];
    cout << People[x][0]*a + People[x][1] * y << endl;
    return 0;
}
void fib() {
    for (int i = 1; i < 23; i++) {
        if (i <= 2) {
            Fib[i] = 1;
            continue;
        }
        Fib[i] = Fib[i-1] + Fib[i-2];
    }
}
*/
/*
//P1106 删数问题    //for循环会在每次循环结束后将循环变量++，即后置++
#include <bits/stdc++.h>
using namespace std;
string n;
int k;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n.length() && k > 0; i++) {
        if (n[i+1] == '\0') {
            n.erase(i,1);
            i = -1;
            k--;
        }
        else if (n[i] > n[i + 1]) {
            n.erase(i,1);
            k--;
            i = -1;
        }
    }
    while (n[0] == '0' && n[1] != '\0') {
        n.erase(0, 1);
    }
    if (n.length() == 0) {
        cout << 0 << endl;
    }
    else {
        cout << n << endl;
    }
    return 0;
}
*/
/*
//P3397 地毯
#include <bits/stdc++.h>
using namespace std;
int arr[1005][1005];
int marr[1005][4];
int n,m;
int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        scanf("%d",&marr[i][0]);
        scanf("%d",&marr[i][1]);
        scanf("%d",&marr[i][2]);
        scanf("%d",&marr[i][3]);
    }
    for(int i=0;i<m;i++) {
        for(int j=marr[i][0];j<=marr[i][2];j++) {
            for(int k=marr[i][1];k<=marr[i][3];k++) {
                arr[j][k]+=1;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/
/*
//P1002 [NOIP2002 普及组] 过河卒 //十年oi一场空，不开long long 见祖宗
#include <bits/stdc++.h>
using namespace std;
int Bx,By,horseX,horseY;
int arr[30][30];
long long int dp[30][30];
void initArr();
void DP();
int main() {
    cin >> By >> Bx >> horseY >> horseX;
    initArr();
    DP();
    cout << dp[Bx][By];
    // for (int i = 0; i <= Bx; i++) {
    //     for (int j = 0; j <= By; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    //}
    return 0;
}

void initArr() {
    arr[horseX][horseY] = -1;
    arr[horseX-2][horseY-1] = -1;
    arr[horseX-1][horseY-2] = -1;
    arr[horseX+2][horseY-1] = -1;
    arr[horseX+1][horseY-2] = -1;
    arr[horseX-2][horseY+1] = -1;
    arr[horseX-1][horseY+2] = -1;
    arr[horseX+2][horseY+1] = -1;
    arr[horseX+1][horseY+2] = -1;
    arr[Bx][By] = 1;
}

void DP() {
    for (int i=0; i<=Bx; i++) {
        for (int j=0; j<=By; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            }
            else if (i == 0 && arr[i][j] != -1) {
                dp[i][j] = dp[i][j-1];
            }
            else if (j == 0 && arr[i][j] != -1) {
                dp[i][j] = dp[i-1][j];
            }
            else if (arr[i][j] != -1) {
                dp[i][j] += dp[i-1][j]+dp[i][j-1];
            }
        }
    }
}
*/
/*
//P1004 [NOIP2000 提高组] 方格取数 //此题不能用贪心写dp，两次的最优解并非是总体最优解。
#include <bits/stdc++.h>
using namespace std;
int arr[15][15];
int dp[15][15];
int N;
int DP();
int main() {
    cin >> N;
    int x,y,n;
    do {
        cin >> x >> y >> n;
        arr[x][y] = n;
    }
    while (n != 0);

    return 0;
}

int DP() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0) {
                dp[i][j] = dp[i][j-1] + arr[i][j];
            }
            else if (j == 0) {
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j];
            }
        }
    }
}
*/
/*
//P1028 [NOIP2001 普及组] 数的计算
#include <bits/stdc++.h>
using namespace std;
int arr[1005];
int N;
int function1(int a);
int main() {
    cin >> N;
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 2;
    function1(N);
    cout << arr[N] << endl;
    return 0;
}

int function1(const int a) {

    if (arr[a] != 0 ) return arr[a];
    if (a%2 == 1 && arr[a-1] != 0) {
        arr[a] = arr[a-1];
        return arr[a];
    }
    int sum = 0;

    for (int i = 0; i <= a/2; i++) {
        if (arr[i] == 0) {
            function1(i);
        }
        sum += arr[i];

    }
    arr[a] = sum;
    return sum;
}
*/
/*
//P10579 [蓝桥杯 2024 国 A] 最长子段
#include <bits/stdc++.h>
using namespace std;
int arr[300010];
int n,a,b,c;
bool sum;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long sum = 0;

    return 0;
}
*/
/*
// quickSort
#include <bits/stdc++.h>
using namespace std;
int arr[100010];
int N;
void quickSort(int l,int r);
int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    quickSort(0,N-1);
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

void quickSort(int l,int r) {
    if (r <= l) return;
    int i = l-1, j = r+1;
    int pivot = arr[(l+r+1)/2];
    while (i < j) {
        do i++; while (arr[i] < pivot);
        do j--; while (arr[j] > pivot);
        if (i < j) swap(arr[i], arr[j]);
    }
    quickSort(l,i-1);
    quickSort(i,r);
}
*/
/*
//P2249 【深基13.例1】查找 //超时且有一个wa，显然是二分写的有问题
#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
int n,m;
int findNum[100005];
int find(int a,int low ,int high);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    for(int i=0;i<m;i++) {
        cin>>findNum[i];
    }
    for (int i = 0; i < m; i++) {
        cout << find(findNum[i],1,n) << " ";
    }
    cout << endl;
    return 0;
}

int find(int a,int low = 1,int high = n) {
    if(low==high && arr[low] != a) {
        return -1;
    }
    if (arr[high] == a) {
        while (arr[high - 1] == a) {
            high--;
        }
        return high;
    }
    if (arr[low] == a) {
        while (arr[low - 1] == a) {
            low--;
        }
        return low;
    }
    if(low+1 == high && arr[high] != a) {
        return -1;
    }
    if (arr[(high+low+1)/2] > a) {
        return find(a,low,(high+low+1)/2);
    }
    else{
        return find(a,(high+low+1)/2,high);
    }
}
/*
//T474063 「Diligent-OI R1 A」DlgtPattern
#include <bits/stdc++.h>
using namespace std;
int main() {
    int x,y,p,q;
    cin>>x>>y>>p>>q;
    cout << min(min(x-p,p),min(y-q,q)) << endl;
    return 0;
}
*/
/*
//T530603 「Diligent-OI R1 B」DlgtArray      //用前缀和直接秒了，暴力枚举会导致TEL
#include <bits/stdc++.h>
using namespace std;
int n,q;
int arrN[1000005];
int arrSum[1000005];    //前缀和
int find(int l,int r,int k);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arrN[i];
        arrSum[i] = arrSum[i - 1] + arrN[i];
    }
    int l,r,k;
    for (int i = 0; i < q; i++) {
        cin >> l >> r >> k;
        cout << find(l, r, k) << '\n';
    }
    for (int i = 0; i < q; i++) {

    }
    return 0;
}

int find(int l,int r,int k) {
    if (r-l < k) return -1;
    int produck = 0;
    int sum = arrSum[r] - arrSum[l-1];
    if (sum == r - l + 1) {
        produck = 1;
    }
    if (r-l+1 < k && produck == 0) return -1;
    if (produck == 1) {
        if (k+1 == sum) return 0;
        return sum-k;
    }
    return abs(k-sum + produck);
}
*/
/*
//T454254 「Diligent-OI R1 D」DlgtTemplate
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[3005];
int arrDel[3005];
struct dp{
    int num;
    int num2;
    int fangAn2[3005];
    int fangAn[3005];
    int ans;
}dp[3005];
void delListI(int *list,int i,int length) {
    for (int j = i; list[j] || list[j+1]; j++) {
        list[j] = list[j+1];
    }
}
//将一个dp结构体传入，并返回选了格子m后的结构体
struct dp delNum(struct dp aa,int m) {
    if (aa.num < arrDel[m]) {
        aa.num2++;
        aa.num ++;
        aa.fangAn[aa.num-1] = m;
        aa.fangAn2[aa.num2-1] = m;
        aa.ans += arr[m];
        return aa;
    }
    int i = 0;
    while (i<arrDel[m]) {
        aa.ans -= arr[aa.fangAn[0]];
        delListI(&aa.fangAn[0],0,aa.num);
        aa.num--;
        i++;
    }
    aa.num ++;
    aa.num2 ++;
    aa.fangAn[aa.num-1] = m;
    aa.ans += arr[m];
    aa.fangAn2[aa.num2-1] = m;
    return aa;
}
void dpFunc() {
    dp[0].num = 0;
    dp[0].ans = 0;
    for(int i=1;i<=n;i++) {
        struct dp aa = delNum(dp[i-1],i);
        if (dp[i-1].ans < aa.ans) {
            dp[i] = aa;
        }
        else {
            dp[i] = dp[i-1];
        }
    }
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>arrDel[i];
    }
    dpFunc();
    cout << dp[n].num2 << '\n';
    for (int i = 0; i < dp[n].num2; i++) {
        cout << dp[n].fangAn2[i] << ' ';
    }
    cout << '\n';
    cout << dp[n].ans << '\n';
    return 0;
}
*/
/*
//P2249 【深基13.例1】查找
#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
int n,m;
int findNum[100005];
int find(int a,int low ,int high);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    for(int i=0;i<m;i++) {
        cin>>findNum[i];
    }
    for (int i = 0; i < m; i++) {
        cout << find(findNum[i],1,n) << " ";
    }
    cout << endl;
    return 0;
}

int find(int a,int low = 1,int high = n) {
    while(low<high) {
        int mid = (low+(high-1))/2;
        if(arr[mid] >= a) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    if (arr[low] == a) return low;
    return -1;
}
*/
/*
//P1359 租用游艇
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[205][205];
int dp[205][205];
void dpFunction();
int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = n-i; j > 0;j--) {
            cin >> arr[i][j];
        }
    }
    return 0;
}

void dpFunction() {

}
*/
/*
//无用代码
#include <stdio.h>
int main() {
    int numbers[8];
    int sum = 0;
    double average;
    for (int i = 0; i < 8; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }
    average = sum / 8.0;
    printf("sum=%d,aver=%.2f\n", sum, average);
    return 0;
}
*/
/*
//无用代码
#include <stdio.h>
#define N 12
void input(float a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }
}
void output(float a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%8.1f", a[i]);
    }
    printf("\n");
}
void sort(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                // 交换 a[i] 和 a[j]
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main() {
    float arr[N];
    input(arr, N);
    sort(arr, N);
    output(arr, N);
    return 0;
}
*/
/*
//B3612 【深进1.例1】求区间和
#include <bits/stdc++.h>
using namespace std;
const int numLength = 100005;
int sumArr[numLength];
int findArr[numLength][2];
int n,m;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin >> sumArr[i];
        sumArr[i] += sumArr[i-1];
    }
    cin >> m;
    for(int i=1;i<=m;i++) {
        cin>>findArr[i][0]>>findArr[i][1];
    }
    for(int i=1;i<=m;i++) {
        cout << sumArr[findArr[i][1]] - sumArr[findArr[i][0] - 1] << endl;
    }
    return 0;
}
*/
/*
//P5638 【CSGRound2】光骓者的荣耀
#include <bits/stdc++.h>
using namespace std;
const long long arrLength = 1000005;
int n,k;
long long arr[arrLength];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    long long max = 0;
    for (int i = k; i <= n; i++) {
        if (arr[i] - arr[i - k] > max) {
            max = arr[i] - arr[i - k];
        }
    }
    cout << arr[n] - max << endl;
    return 0;
}
*/
/*
//P1000 超级玛丽游戏  //一直在我的尝试界面挂着，太难看了
#include<bits/stdc++.h>
int main()
{
    std::cout<<R"(                ********
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
##########################################    ############ )";
}
*/
/*
//P1013 [NOIP1998 提高组] 进制位
#include <bits/stdc++.h>
using namespace std;
int n;
char arr[15][15];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    return 0;
}
*/
/*
//P11273 「Diligent-OI R1 C」DlgtRank
#include <bits/stdc++.h>
using namespace std;
int n,k;
struct arr {
    int num;
    int ranking;
    int ciShu;
}arr[200005];
int sum[200005];
bool sortCmp(struct arr a,struct arr b) {
    return a.num<b.num;
}
bool sortCmp2(struct arr a,struct arr b) {
    return a.ranking<b.ranking;
}
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>arr[i].num;
        arr[i].ranking = i;
        arr[i].ciShu = 0;
    }

    sort(arr,arr+n,sortCmp);
    bool a = true;
    while(a) {
        a = false;
        for(int i=1;i<=n;i++) {
            int j = i+1;
            while (arr[i].num == arr[j].num) {
                j++;
            }
            if (arr[j].num - arr[i].num >= k) {
                for(int m = i;m<j;m++) {
                    arr[k].num+=k;
                }
                i=j;
            }
            else {
                arr[i].ciShu++;
                a = true;
            }
        }
    }
    sort(arr,arr+n,sortCmp2);
    for(int i=1;i<=n;i++) {
        cout<<arr[i].ciShu<<" ";
    }
    return 0;
}
*/
/*
//P3799 小 Y 拼木棒 //缺少一个特判，当j == i-j && arr[j]<2时，应是C2_1结果应为0
#include <bits/stdc++.h>
using namespace std;
const int modNum = 1e9+7;
int arr[100005];
int n;
long long num=0;
int maxNum = 0;
long long C2x(int x) {
    if(x == 1) return 0;
    return x*(x-1)/2;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (a > maxNum) {
            maxNum = a;
        }
        arr[a]++;
    }
    for (int i = 2; i <= maxNum+5; i++) {
        if (arr[i] >= 2) {
            for (int j = 1; j <=i/2;j++) {
                if (arr[j] != 0 && arr[i-j] != 0) {
                    if (j == i-j && arr[j] < 2) {
                        continue;
                    }
                    else if (j == i-j) {
                        num+=C2x(arr[i])%modNum*C2x(arr[j])%modNum;
                    }
                    else {
                        num+=(C2x(arr[i])%modNum)*arr[j]*arr[i-j]%modNum;
                    }
                }
            }
        }
    }
    cout << num%modNum << endl;
    return 0;
}
*/
/*
//P1706 全排列问题
#include <bits/stdc++.h>
using namespace std;
int n;
bool arr[15];
vector <int> pr;
void dfs(int a);
int main() {
    cin>>n;
    dfs(0);
    return 0;
}
void dfs(int a) {
    if (a == n) {
        for (int j : pr) {
            cout<< setw(5)<<j;
        }
        cout<<"\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            arr[i] = true;
            pr.push_back(i);
            dfs(a+1);
            arr[i] = false;
            pr.pop_back();
        }
    }
}
*/
/*
//P8665 [蓝桥杯 2018 省 A] 航班时间 //peek查看下一个输入字符，setw控制输出宽度，setfill控制补齐字符
#include <bits/stdc++.h>
using namespace std;
int T;
int timeS[20000];
int inputToSecond();
void outputToTime(int seconds);
int main() {
    cin >> T;
    for (int i = 1; i <= T*2; i++) {
        timeS[i] = inputToSecond();
    }
    for(int i = 1; i <= T*2; i+=2) {
        outputToTime((timeS[i]+timeS[i+1])/2);
    }
    return 0;
}

int inputToSecond() {
    string time,time2,day;
    day = "(+0)";
    cin >> time >> time2;
    if (cin.peek() == ' ') {
        cin >> day;
    }
    int seconds1 = 0,seconds2 = 0;
    seconds1+=(time[0]-'0')*10*3600;
    seconds1+=(time[1]-'0')*3600;
    seconds1+=(time[3]-'0')*10*60;
    seconds1+=(time[4]-'0')*60;
    seconds1+=(time[6]-'0')*10;
    seconds1+=(time[7]-'0');
    seconds2+=(time2[0]-'0')*10*3600;
    seconds2+=(time2[1]-'0')*3600;
    seconds2+=(time2[3]-'0')*10*60;
    seconds2+=(time2[4]-'0')*60;
    seconds2+=(time2[6]-'0')*10;
    seconds2+=(time2[7]-'0');
    seconds2+=(day[2]-'0')*24*60*60;
    return seconds2 - seconds1;
}

void outputToTime(int seconds) {
    int hours = seconds/3600;
    seconds = seconds%3600;
    int minutes = seconds/60;
    seconds = seconds%60;
    cout << setw(2) << setfill('0')<< hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << endl;
}
*/
/*
//P1009 [NOIP1998 普及组] 阶乘之和
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> mul(const vector<int>&A, const vector<int>&B);
vector<int> add(vector<int>&A, vector<int>&B);
vector<int> jieCheng(int m);
int main() {
    cin >> n;
    vector<int> Print = {0};
    for (int i = 1; i <= n; i++) {
        vector<int> A = jieCheng(i);
        vector<int> B = add(A, Print);
        Print = B;
    }
    for (int i = Print.size()-1; i >= 0; i--) {
        cout << Print[i];
    }
    return 0;
}

vector<int> mul(const vector<int> &A, const vector<int> &B) {
    vector<int> C(A.size()+B.size()+1,0);
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            C[i+j] += A[i]*B[j];
            C[i+j+1] += C[i+j]/10;
            C[i+j] %=10;
        }
    }
    while (C.size()>1 && C.back() == 0) C.pop_back();
    return C;
}
vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C(max(A.size(),B.size())+1,0);
    if (A.size()<B.size()) add(B,A);
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) {
            t += B[i];
        }
        C[i] = t%10;
        t = t / 10;
    }
    while (C.size()>1 && C.back() == 0) C.pop_back();
    return C;
}

vector<int> jieCheng(int m) {
    vector<int> print;
    print.push_back(1);
    for (int i = 2; i <= m; i++) {
        vector<int> N;
        N.push_back(i%10);
        N.push_back(i/10);
        print = mul(print,N);
    }
    return print;
}
*/
/*
//A - Flag
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int temp;
            do temp = cin.get();
            while( '0' > temp || temp > '9' );
            a[i][j] = temp;
        }
    }
    bool b = true,c = true;
    for(int i=0;i<n;i++) {

        for(int j=0;j<m-1;j++) {
            b = a[i][j] == a[i][j+1] && b;
        }
    }
    for(int i=0;i<n-2;i++) {
        for(int j=0;j<m;j++) {
            c = (a[i][j] != a[i+1][j]) && (a[i+1][j] != a[i+2][j]) && c;
        }
    }
    if (b && c) cout << "YES";
    else cout << "NO";
    return 0;
}
*/
/*
//B - Football
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string name[110];
    for (int i = 0; i < n; i++) {
        cin >> name[i];
    }
    int win1[2] = {0, 0};
    sort(name,name+n);
    for (int i = 0; i < n; i++) {
        if (name[i] == name[0]) {
            win1[0]+=1;
        }
        else {
            win1[1] += 1;
        }
    }
    if (win1[0] > win1[1]) cout << name[0];
    else cout << name[n-1];
    return 0;
}
*/
/*
//D - Sale
#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[105];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (arr[i]>0) break;
        ans += arr[i];
    }
    cout << -ans;
    return 0;
}
*/
/*
//C - MEX Repetition    //没思路
#include <bits/stdc++.h>
using namespace std;
int t;
void func();
int main() {
    cin>>t;
    while(t--) {
        func();
    }
    return 0;
}
void func() {
    int n,k;
    bool ifIn[1e5+10] = {false};
    cin>>n>>k;
    int arr[1e5+10];
    for (int i = 0; i < n;i++) {
        cin >> arr[i];
        ifIn[arr[i]] = true;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int m = 0;
            for (; m < 1e5+10; m++) {
                if (ifIn[m]) break;
            }
            ifIn[arr[j]] = false;
            ifIn[m] = ;
            arr[j] = m;
        }
    }
}
*/
/*
//P2670 [NOIP2015 普及组] 扫雷游戏
#include <bits/stdc++.h>
using namespace std;
string arr[110];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]=='*') {
                cout<<"*";
            }
            else {
                int num = 0;
                if(i >= 1 && arr[i-1][j]=='*') {
                    num++;
                }
                if(i >= 1 && j>=1 && arr[i-1][j-1]=='*') {
                    num++;
                }
                if(i >= 1 && arr[i-1][j+1]=='*') {
                    num++;
                }
                if(j >= 1 && arr[i][j-1]=='*') {
                    num++;
                }
                if(arr[i][j+1]=='*') {
                    num++;
                }
                if(j >= 1 && arr[i+1][j-1]=='*') {
                    num++;
                }
                if(arr[i+1][j]=='*') {
                    num++;
                }
                if(arr[i+1][j+1]=='*') {
                    num++;
                }
                cout<<num;
            }
        }
        cout << '\n';
    }
    return 0;
}
*/
/*
//P1138 第 k 小整数
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int max = 0;
    bool arr[30005] = {false};
    int a;
    for(int i=0;i<n;i++) {
        cin>>a;
        if(a>max) {
            max = a;
        }
        arr[a] = true;
    }
    for(int i=1;i<=max;i++) {
        if(arr[i]==true) {
            k--;
        }
        if(k == 0) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"NO RESULT"<<endl;
    return 0;
}
*/
/*
//P1004 [NOIP2000 提高组] 方格取数
#include <bits/stdc++.h>
using namespace std;
int arr[12][12];
int N;
int dp[25][15][15]; //第一个表示两人一共走了几步，第二个和第三个表示两个人分别向右走的次数。即i-j表示第一个人向下走的次数
void dpFunc();
int main() {
    cin >> N;
    int i, j, k;
    do {
        cin >> i >> j >> k;
        arr[i][j] = k;
    }
    while(i && j && k);
    dpFunc();
    cout << dp[N*2][N][N] << endl;
    return 0;
}
void dpFunc() {
    for (int i = 1; i <= N*2; i++) {
        for (int j = 1; j <= i; j++) {
            if (j > N) break;
            for (int k = 1; k <= i; k++) {
                if (k > N) break;
                dp[i][j][k] = max(max(dp[i-1][j][k], dp[i-1][j-1][k-1]),
                    max(dp[i-1][j][k-1], dp[i-1][j-1][k]))
                +arr[j][i-j] + arr[k][i-k];
                if(j == k) {
                    dp[i][j][k] -= arr[j][i-j];
                }
            }
        }
    }
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << "Hello World!" << endl;
    return 0;
}
*/
/*
//emmm
#include <bits/stdc++.h>
using namespace std;
int main() {
    char a,b,c;
    cin>>a>>b>>c;
    char *aPtr = &a;
    char *bPtr = &b;
    char *cPtr = &c;
    char *temp = nullptr;
    if (*aPtr>*bPtr) swap(aPtr,bPtr);
    if (*bPtr>*cPtr) swap(cPtr,bPtr);
    if (*aPtr>*bPtr) swap(aPtr,bPtr);
    //if (*bPtr>*cPtr) swap(cPtr,bPtr);
    cout << *aPtr<<" "<<*bPtr<<" "<<*cPtr;
    return 0;
}
*/
/*
//B3637 最长上升子序列
#include <bits/stdc++.h>
using namespace std;
int arr[5010];
int n;
int dpArr[1000010]; //下标记录的是以i结尾的最大的子序列长度，另一种更好的做法是以ai结尾的最长子链长度。
void dpFunc();
int main() {
    cin>>n;
    int maxa = 0;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        if (arr[i] > maxa) maxa = arr[i];
    }
    dpFunc();
    int max = 0;
    for (int j = maxa ; j > 0;j--) {
        if (dpArr[j] > max) max = dpArr[j];
    }
    cout<<max;
    return 0;
}
void dpFunc(){
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) dpArr[1] = 1;
        int maxNum = 0;
        for (int j = 1 ; j < arr[i];j++) {
            if (dpArr[j] > maxNum) maxNum = dpArr[j];
        }
        dpArr[arr[i]] = max(maxNum+1,dpArr[arr[i]]);
    }
}
*/
/*
//B3637 最长上升子序列
#include <bits/stdc++.h>
using namespace std;
int arr[5010];
int n;
int dpArr[5010]; //以ai结尾的最长子链长度。
void dpFunc();
int main() {
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>arr[i];
    }
    dpFunc();
    int maxNum = 0;
    for (int i = 1; i <= n; i++) {
        if (dpArr[i] > maxNum) maxNum = dpArr[i];
    }
    cout<<maxNum;
    return 0;
}
void dpFunc(){
    for (int i = 1; i <= n; i++) {
        dpArr[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                dpArr[i] = max(dpArr[i], dpArr[j] + 1);
            }
        }
    }
}
*/
/*
//P1020 [NOIP1999 提高组] 导弹拦截
#include <bits/stdc++.h>
using namespace std;
int arr[100010];
//int dpArr[100005];
int Tow1[100010];
int Tow[100010];
long long n = 0;
long long num = 0;
void Func(int i);
void Func2(int i);
int main() {
    //输入部分
    //in 90 103 99 83 102 70 86 70 99 71
    //out 5 3
    //ios_base::sync_with_stdio(false);
    do {
        if (!('0' <=cin.peek() && cin.peek() <= '9')) {break;}
        n++;
        cin >> arr[n];
    }
    while (getchar() == ' ');
    // 第一问
     //应为单调增序列，从最小值开始遍历，若发现ai大于某值则用其进行拦截。
    for (int i = 1; i <= n; i++) {
        Func(i);
    }
        // for (int j = 1; j < 100005; j++) {
        //     if (Tow1[j] == 0) {
        //         Tow1[j] = arr[i];
        //         num++;
        //         break;
        //     }
        //     if (arr[i] > Tow1[j]) {
        //         Tow1[j] = arr[i];
        //         break;
        //     }
        // }
    // for (int i = 1; i <= n; i++) {
    //     dpArr[i] = 1;
    //     for (int j = 1; j < i; j++) {
    //         if (arr[i] <= arr[j]) dpArr[i] = max(dpArr[i], dpArr[j] + 1);
    //     }
    // }
    // int maxNum = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (dpArr[i] > maxNum) maxNum = dpArr[i];
    // }
    cout << num << endl;
    //第二问
    num = 0;
     //应为单调增序列，从最小值开始遍历，若发现ai大于某值则用其进行拦截。
    for (int i = 1; i <= n; i++) {
        Func2(i);
    }
    //     for (int j = 1; j < 100005; j++) {
    //         if (Tow[j] == 0) {
    //             Tow[j] = arr[i];
    //             num++;
    //             break;
    //         }
    //         if (arr[i] <= Tow[j]) {
    //             Tow[j] = arr[i];
    //             break;
    //         }
    //     }
    // }
    cout << num << endl;
    return 0;
}
bool upperCmp(const int val, const int a) {
    return val > a;
}
void Func(int i) {  //严格上升子序列数量
    if (Tow1[num] >= arr[i] || num == 0) {
        Tow1[num+1] = arr[i];
        num++;
        return;
    }
    *upper_bound(Tow1+1, Tow1+num+1, arr[i],upperCmp) = arr[i];
}
bool upperCmp2(const int val, const int a) {
    return val <= a;
}
void Func2(int i) {  //严格上升子序列数量
    if (Tow[num] < arr[i] || num == 0) {
        Tow[num+1] = arr[i];
        num++;
        return;
    }
    *upper_bound(Tow+1, Tow+num+1, arr[i],upperCmp2) = arr[i];
}
*/
