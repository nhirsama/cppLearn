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
//T530603 「Diligent-OI R1 B」DlgtArray
#include <bits/stdc++.h>
using namespace std;
int n,q;
int arrN[1000005];
int find(int l,int r,int k);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arrN[i];
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
    int produck = 1;
    int sum = 0;
    for (int i = l; i <= r; i++) {
        if (arrN[i] == 0) {
            produck = 0;
            continue;
        }
        sum ++;
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