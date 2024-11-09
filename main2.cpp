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
#include <bits/stdc++.h>
using namespace std;
int main() {
    return 0;
}