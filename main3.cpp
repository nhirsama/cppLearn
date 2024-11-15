/*
//模板
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {

    return 0;
}
*/
/*
//P4414 [COCI2006-2007#2] ABC，乐了，好像是我选成cpp语法了，难怪一直说我超时。
#include <iostream>
using namespace std;
int main() {
    int arr[3];
    char a,b,c;
    cin >> arr[0] >> arr[1] >> arr[2];
    for (int i = 0; i < 2; i++) {
        int temp;
        for (int j = 0; j < 3-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        cin >> a;
        switch (a) {
            case 'A': {
                cout << arr[0] << ' ';
                continue;
            }
            case 'B': {
                cout << arr[1] << ' ';
                continue;
            }
            case 'C': {
                cout << arr[2] << ' ';
            }
        }
    }
    return 0;
}
*/
/*
//B2106 矩阵转置
#include <iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cout<<a[j][i]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
*/
/*
//思路有误，重新写一遍
//P1028 [NOIP2001 普及组] 数的计算
#include <iostream>
#include <math.h>
using namespace std;
void printarr(int arr[]) {
    cout << '[';
    for (int i = 0; i < 12; i++) {
        cout << arr[i] << " ";
    }
    cout << ']' << endl;
}
int main() {
    int arr[12] = {0};
    cin>>arr[0];
    int num = 1;
    for(int i=0;i<arr[0]/2+1;i++) { //一共要加n/2次
        for(int j=0;j<sqrt(arr[0]);j++) {   //每一位都要遍历
            for (int k=0;k<arr[j]/2+1;k++) {    //每一位便利上一位的一半次
                if(arr[j+1] < arr[j]/2 || arr[j] == arr[j+1]*2) {
                arr[j+1]++;
                num++;
                }
            }
            for (int k=j+1;k<12;k++) {
                arr[k] = 0;
            }

        }
        // for(int j=0;j<sqrt(arr[0])+1;j++) {
        //     for(int k=0;k<=(arr[j-1]/2);k++) {
        //         if (arr[j+1] < arr[j]/2) {
        //             arr[j+1]++;
        //             for (int n=j+2; n<sqrt(arr[0])+1; n++) {
        //                 arr[n] = 0;
        //             }
        //             num++;
        //             printarr(arr);
        //         }
        //     }
        // }
    }
    cout<<num<<endl;
    return 0;
}
*/
/*
//P1028 [NOIP2001 普及组] 数的计算
#include <iostream>
#include <math.h>
//直接递归会超时，因此将递归的结果记录进数组中，以进行查找。
int arr[50][2] = {{256,692004},{512,30251722},{128,27338},{64,1828},{700,199855092}};
using namespace std;
int f(int n) {
    int num = 0;
    if (n <= 1) return 1;
    for (int i = 1; i <= sqrt(n)+1; i++) {
        if (n % 2 == 0) {
            if (arr[i][0] == n) {
                return arr[i][1];
            }
        }
        else {
            if (arr[i][0] == n-1) {
                return arr[i][1];
            }
        }
    }
    for (int i = 0; i <= n/2; i++) {
        num+=f(i);
    }
    for (int i = 0; i <= sqrt(n)+1; i++) {
        if(arr[i][0] == 0) {
            arr[i][0] = n;
            arr[i][1] = num;
        }
    }
    return num;
}
int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
*/
/*
//P5728 【深基5.例5】旗鼓相当的对手
#include <iostream>
using namespace std;
int N;
int num = 0;
void printlist(int *arr) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            cout << *arr++ << " ";
        }
        cout << endl;
    }
 }

int main() {
    cin >> N;
    int arr[N][5];
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        arr[i][3] = (arr[i][0] + arr[i][1] + arr[i][2]);
        arr[i][4] = i+1;
    }
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j<N-i-1;j++) {
            if (arr[j+1][3] < arr[j][3]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j<N;j++) {
            if (arr[j][3] - arr[i][3] <=10 &&
                arr[i][0] - arr[j][0] <= 5 &&
                arr[i][1] - arr[j][1] <= 5 &&
                arr[i][2] - arr[j][2] <= 5 &&
                arr[i][0] - arr[j][0] >= -5 &&
                arr[i][1] - arr[j][1] >= -5 &&
                arr[i][2] - arr[j][2] >= -5) {
                num++;
            }
        }
    }
     //printlist(&arr[0][0]);
    cout << num << endl;
    return 0;
}
*/
/*
//P1851 好朋友
#include <iostream>
#include <math.h>
using namespace std;
int s;
//int arr[1000][3] = {{0,0}};
int gitYueShu(int s) {
    int sum = 0;
    for (int i = 2; i <= s/2+1; i++) {
        if (s%i == 0) {
            sum+=i;
        }
    }
    return sum+1;
}
int main() {
    cin >> s;
    int Asum,Bsum;
    for (int i = s; i <= s*s; i++) {
        Asum = gitYueShu(i);
        Bsum = gitYueShu(Asum);
        if (Asum == i) {
            continue;
        }
        if (Bsum == i ) {
            cout << i << ' ' << Asum << endl;
            return 0;
        }
    }
    return 0;
}
*/
/*
//B - Sakurako and Water
#include <iostream>
#include <math.h>
using namespace std;
int t,n;

void ceshi() {
    int sum = 0;
    cin >> n;
    int arr[n][n];
    int arm[2*n-1] = {0};
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (arm[i-j+n-1] > arr[i][j]) {
                arm[i-j+n-1] = arr[i][j];
            }
        }
    }
    for (int i = 0; i < 2*n-2; i++) {
        sum+=arm[i];
    }
    sum = -sum;
    for (int i = 0; i < n; i++) {
    cout << sum << endl;
    }
}
int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        ceshi();
    }
    return 0;
}
*/
/*
//P1094 [NOIP2007 普及组] 纪念品分组
//冒泡超时了，草
#include <iostream>
#include<algorithm>
using namespace std;
int w,n;
//冒泡排序
void PaiXu(int arr[]) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-1-i;j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
using namespace std;
int main() {

    cin>>w>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    PaiXu(arr);
    int num = 0,i = 0;
    int n2 = n-1;
    while(i <= n2) {
        if(arr[i]+arr[n2] <= w) {
            num++;
            i++;
            n2--;
        }
        else {
            num++;
            n2--;
        }
    }
    cout << num << endl;
    return 0;
}
*/
/*
//P2141 [NOIP2014 普及组] 珠心算测验
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int &i : arr) {
        cin >> i;
    }
    int num = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=i+1; k<n; k++) {
                for (int l=i+1; l<n; l++) {
                    if (i != j && i != k && j != l &&
                        j != k && j != l && k != l) {
                        continue;
                    }
                    else if (arr[i] + arr[j] == arr[k] + arr[l]) {
                        num++;
                    }
                }
            }
        }
    }
    cout << num << endl;
    return 0;
}
*/
/*
//P1554 梦中的统计
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M,N;
ll arr[10] = {0};
int main() {
    cin>>M>>N;
    ll Q = N-M;
    int lin = (int)log10(M);
    for (ll num = M; num <= N; num++) {
        ll num2 = num;
        for (ll i = 1; i <= lin+1; i++) {
            arr[num2%10]++;
            num2 /= 10;
        }
    }
    for (ll i : arr) {
        cout << i << ' ';
    }
    return 0;
}
*/
/*
//P1048 [NOIP2005 普及组] 采药
#include <bits/stdc++.h>
using namespace std;
int T,M;
int arr[100][2];
int dp[100][1000];
void DP() {
    for (int i = 1; i <= M ;i++) {
        for (int j = 1; j <= T; j++) {
            if (j < arr[i][1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j],dp[i-1][j - arr[i][1]]+ arr[i][0]);
            }
        }
    }
}
int main() {
    cin >> T >> M;
    for (int i = 0; i < M; i++) {
        cin >> arr[i][1] >> arr[i][0];
    }
    for (int i = 0; i < 100; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < 1000; i++) {
        dp[0][i] = 0;
    }
    DP();
    cout << dp[M][T] << endl;
    return 0;
}
*/
/*
//P1216 [USACO1.5] [IOI1994]数字三角形 Number Triangles
#include <bits/stdc++.h>
using namespace std;
int arr[1005][1005];
int r;
int dp[1005][1005];
void DP() {
    dp[0][0] = arr[0][0];
    for (int i = 1; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            }
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
        }
    }
}
int main() {
    cin>>r;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < i+1; j++) {
            scanf ("%d", &arr[i][j]);
        }
    }
    int maxdp = 0;
    DP();
    for (int i = 0; i <= r; i++) {
        if (dp[r-1][i]>maxdp) {
            maxdp = dp[r-1][i];
        }
    }
    cout<<maxdp<<endl;
    return 0;
}
*/
/*
//第八次集训Quests
#include <bits/stdc++.h>
using namespace std;
int t;
void func();
int main() {
    cin >> t;
    while (t) {
        func();
    }
    return 0;
}
void func() {
    int n,k;
    cin >> n >> k;
    int arr[n];
    int arrB[k];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> arrB[i];
    }


}
*/
/*
//B - Kosuke's Sloth
#include <bits/stdc++.h>
using namespace std;
const long long int Length = 10000000;
const int modNum = 1000000007;
long long int Fib[Length];
void Fibonacci();
long long int Fibonacci(long long int a);
int main() {
    int t;
    cin>>t;
    Fibonacci();
    while(t--) {
        int n,k;
        cin>>n>>k;
        int num = 0;
        for (long long int i = 1; i < 10000000000; i++) {
            if (Fibonacci(i) % k == 0) {
                num++;
                if (num == n) {
                    cout << i%modNum<< endl;
                    break;
                }
            }
        }
    }
    return 0;
}
void Fibonacci() {
    Fib[0] = 0;
    Fib[1] = 1;
    Fib[2] = 1;
    for (int i = 3; i < 1000; i++) {
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    }
}
long long int Fibonacci(long long int a) {
    if (a < Length) {
        return Fib[a];
    }
    else {
        return Fibonacci(a-1)+Fibonacci(a-2);
    }
}
*/
/*
//第八次集训Quests
#include <bits/stdc++.h>
using namespace std;
long long int Fib[10000];
void Fibonacci() {
    Fib[0] = 0;
    Fib[1] = 1;
    Fib[2] = 1;
    for (int i = 3; i < 1000; i++) {
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    }
}
int main() {
    int t;
    cin>>t;
    Fibonacci();
    while (t--) {
        long long int n,k;
        cin>>n>>k;
        for (int i = 1; i <= n; i++) {
            if (k == 1) {
                cout<<n<<"\n";
                break;
            }
            if (Fib[i]%k == 0) {
                long long int a = (i+((k+1)*(n-1)));
                a = a%1000000007;
                cout << a << endl;
                break;
            }
        }
    }
    return 0;
}
*/