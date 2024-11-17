/*
//模板
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
/*
//环境测试
#include <bits/stdc++.h>
using namespace std;
int main(){
    printf("Hello World\n");
}
*/
/*
////T539820 202411A Giants
#include <bits/stdc++.h>
using namespace std;
int main() {
    int type ,A,B,C,D;
    cin>>type>>A>>B>>C>>D;
    if(type==0) cout <<A+B;
    else if(type==1) cout <<max(A-C,0)+max(B-D,0);
    return 0;
}
*/
/*
//T539821 202411B Legends Never Die
#include <bits/stdc++.h>
using namespace std;
int main() {
    int A,B,C,K;
    cin>>A>>B>>C>>K;
    if(A+B>=K) cout << "Yes\n";
    else cout<<"No\n";
    if(A+C>=K) cout << "Yes\n";
    else cout<<"No\n";
    if(C+B>=K) cout << "Yes\n";
    else cout<<"No\n";
    return 0;
}
*/
/*
//T539822 202411C K/D/A
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int ans = 0;
    int Num = 0;
    cin >> n;
    for (int i = 1; i <=n; i++) {
        int K,D,A;
        scanf("%d/%d/%d",&K,&D,&A);
        int S = 0;
        if (K-D >= 10) S = K*(K-D)+A;
        else if (K >=D) S = (K-D+1)*3 +A;
        else S = A*2;
        if (S > ans) {
            ans = S;
            Num = i;
        }
    }
    cout<<Num<<endl;
    return 0;
}
*/
/*
//T539823 202411D Phoenix
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    int arr[n+5];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = n-1; i >= 1; i--) {
        bool A = true;
        for(int j = n;j > i; j--) {
            if(arr[i]<=arr[j]) {
                A = false;
            }
        }
            if(A == true) {
                ans++;
            }
    }
    cout << ans+1 << endl;
    return 0;
}
*/
/*
//T539824 202411E 卡牌
#include <bits/stdc++.h>
using namespace std;
int main() {
    int x,n;
    cin>>x>>n;
    int num=0;
    int arr[6] = {0};
    for(int i=0;i<n;i++) {
        int a = 0;
        for(int j=0;j<5;j++) {
            int b;
            cin>>b;
            if (x>=b) a = max(a,b);
        }
        //cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3]>>arr[i][4];
        if (x>=a) {
            x =x - a;
            num++;
            arr[a]++;
        }
    }
    cout<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<' '<<arr[5]<<endl;
    cout<<x<<endl;
    return 0;
}
*/
/*
//T539825 202411F Rise
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n>>m;
    int arr[1005] = {0};
    vector<int> v;
    for (int i = 0; i < m; i++) {
        int a,b;
        string st;
        cin >> st >> a >> b;
        if (st == "water") {
            for (int j = a; j <= b; j++) {
                arr[j] ++;
            }
        }
        else if (st == "rise") {
            int c;
            cin >> c;
            int ans = 0;
            for (int j = a; j <= b; j++) {
                if (arr[j] >= c) {
                    arr[j] = 0;
                    ans++;
                }
            }
            v.push_back(ans);
        }
    }
    for (const int i : v) {
        cout << i << '\n';
    }
    return 0;
}
*/
/*
//T539826 202411G 三角含数
//暴力肯定TLE，得用搜索
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void Func(int i);
int main() {
    int l,r;
    cin>>l>>r;
    for (int i = l; i <= r; i++) {
        Func(i);
    }
    cout<<ans<<endl;
    return 0;
}
void Func(int i) {
    int l[6];
    int ls[6] = {0,1,0,0,0,0};
    l[0] = i%10;
    i/=10;
    l[1] = i%10;
    i/=10;
    l[2] = i%10;
    i/=10;
    l[3] = i%10;
    i/=10;
    l[4] = i%10;
    i/=10;
    l[5] = i;
    sort(l,l+6);

     if (l[ls[0]]+l[ls[1]] > l[ls[2]] && l[ls[3]]+l[ls[4]] > l[ls[5]]) {
         ans+=1;
     }
}
*/
/*
//T539827 202411H Enemy
#include <bits/stdc++.h>
using namespace std;
char arr[1005][1005];
bool arrbool[1005][1005];
int n,m;
int main() {
    cin>>n>>m;
    //ios_base::sync_with_stdio(false);
    for(int i=1;i<=n;i++) {
        int H = 0;
        int A = 0,B = 0;
        for(int j=1;j<=m;j++) {
            char inp;
            cin>>inp;
            if(inp=='H') H = j;
            if(inp=='A') A++;
            if(inp=='B') B++;
        }
        if(H) {
            for(int j=1;j<H;j++) {
                if(A>0) {
                    arr[i][j] = 'A';
                    A--;
                }
                else {
                    arr[i][j] = '#';
                }
            }
            for(int j=m;j>H;j--) {
                if(B>0) {
                    arr[i][j] = 'B';
                    B--;
                }
                else {
                    arr[i][j] = '#';
                }
            }
            arr[i][H] = 'H';
        }
        else {
            if (A==B) {
                for(int j = 1;j<=m;j++) {
                    arr[i][j] = '#';
                }
                continue;
            }
            int C = '0';
            if (A>B) C = 1;
            if (B>A) C = 2;
            if(C == 1 && A>0) {
                for(int j=m;j>=1;j--) {
                    if(A) {
                        arr[i][j] = 'A';
                        A--;
                    }
                    else{
                        arr[i][j]= '#';
                    }
                }
            }
            if(C == 2 && B>0) {
                for(int j=1;j<=m ;j++) {
                    if(B) {
                        arr[i][j] = 'B';
                        B--;
                    }
                    else {
                        arr[i][j] = '#';
                    }
                }
            }
        }
    }
    //第二问
    //输出
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=m;j++) {
    //         cout<<arr[i][j];
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j] == arr[i+1][j] && arr[i][j] != '#' && arr[i][j] != 'H') {
                arrbool[i][j] = true;
                arrbool[i+1][j] = true;
            }
            //if(arr[i][j] == arr[i][j+1] && arr[i][j] != '#' && arr[i][j] != 'H') {
            //    arr[i][j] = '#';
            //}
            //if(arr[i][j] == arr[i][j-1] && arr[i][j] != '#' && arr[i][j] != 'H') {
            //    arr[i][j] = '#';
            //}
            if(arr[i][j] == arr[i-1][j] && arr[i][j] != '#' && arr[i][j] != 'H') {
                arrbool[i][j] = true;
                arrbool[i-1][j] = true;
            }
        }
    }
    //输出
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arrbool[i][j] == true) arr[i][j] = '#';
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}
*/
/*
//P5707 【深基2.例12】上学迟到
#include <bits/stdc++.h>
using namespace std;
int s,v;
int main() {
    cin>>s>>v;
    int minTime = s/v;
    if (s%v != 0) minTime++;
    minTime += 10;
    if (minTime <= 8*60) {
        int h = minTime / 60;
        if (minTime % 60 != 0) h++;
         minTime %= 60;
        if (minTime == 0) minTime = 60;
        cout<<setw(2)<<setfill('0')<<8-h<<':'<<setw(2)<<60-minTime<<endl;
    }
    else {
        int h = minTime / 60;
        if (minTime % 60 != 0) h++;
        minTime %= 60;
        if (minTime == 0) minTime = 60;
        cout<<setw(2)<<setfill('0')<<8-h+24<<':'<<setw(2)<<60-minTime<<endl;
    }
    return 0;
}
*/
/*
//P2141 [NOIP2014 普及组] 珠心算测验
#include <bits/stdc++.h>
using namespace std;
int arr[105];
int ans[105][105];
int main() {
    int n;
    int num=0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i != j) ans[i][j] = arr[i]+arr[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if(j != k && ans[j][k] == arr[i]) {
                    num++;
                    goto aa;
                }
            }
        }
        aa:
    }
    cout << num << endl;
    return 0;
}
*/
/*
//P5587 打字练习
#include <bits/stdc++.h>
using namespace std;
vector<string> input,example;
int main() {
    string line;
    getline(cin, line);
    while(line != "EOF"){
        example.push_back({});
        for(char c : line) {
            if(c != '<') example.back().push_back(c);
            else if(example.back().back() != 0 )example.back().pop_back();
        }
        getline(cin, line);
    }
    getline(cin, line);
    while(line != "EOF"){
        input.push_back({});
        for(char c : line) {
            if(c != '<') input.back().push_back(c);
            else if(input.back().back() != 0 )input.back().pop_back();
        }
        getline(cin, line);
    }
    int correct = 0;
    int Time;
    cin >> Time;
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == example[i][j]) correct++;
        }
    }
    printf("%.0f\n", static_cast<float>(correct)*60 / static_cast<float>(Time));
    return 0;
}
*/
/*
//P5587 打字练习    //需要注意的是，可能输入的字符串大于范文的字符串，可能会导致数组越界。
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> input,example;
    string line;
    getline(cin, line);
    while (line!="EOF") {
        example.emplace_back();
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '<') {
                if (!example.back().empty()) example.back().pop_back();
            }
            else example.back().push_back(line[i]);
            //else if ('a' <= c && c <= 'z' || c == ' ' || c == '.') example.back().push_back(c);
        }
        getline(cin, line);
    }
    getline(cin, line);
    while (line!="EOF") {
        input.emplace_back();
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '<') {
                if (!input.back().empty()) input.back().pop_back();
            }
            else input.back().push_back(line[i]);
            //else if ('a' <= c && c <= 'z' || c == ' ' || c == '.') input.back().push_back(c);
        }
        getline(cin, line);
    }
    long long correct = 0;
    for (int i = 0; i < input.size(); i++) {    //把这里改成min(input.size(),example.size())也可
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == 0) break;
            if (j >= example[i].size()) break;
            if (input[i][j] == example[i][j]) correct++;
        }
        if (i >= example.size()) break;
    }
    int Time;
    cin >> Time;
    cout<<(long long)(correct*60.0/Time+0.5);
    return 0;
}
*/
/*
//【LGR-205-Div.2】核桃编程 11 月月赛 II & GFOI Round 2
#include <bits/stdc++.h>
using namespace std;
int min1 = 0;
long long num[27];
char Func(char m) {
    int max3 = 0;
    bool aaa = true;
    num[m-'a']--;
    for (int i = 0; i < 26; i++) {
        if (i>1)if (num[i] != num[i-1]) aaa = false;
        if (num[i] < num[max3]) {
            max3 = i;
        }
    }
    // if (aaa) {
    //     //num[m-'a']++;
    //     return m;
    // }
    //num[max3]++;
    num[m-'a']++;
    return max3+'a';
}
int main() {
    int n;
    char arr[1000005];
    char pri[1000005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        num[arr[i]-'a']++;
    }
    for (int i = 0; i < n; i++) {
        pri[i] = Func(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << pri[i];
    }
    return 0;
}
*/
/*
//1097. 池塘计数        //答案错误，重写一遍再
#include <bits/stdc++.h>
using namespace std;
char arr[1005][1005];
int N,M;
bool st[1005][1005];
void Func(int i,int j);
int main() {
    int ans =0 ;
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<=M+1;i++) {
        arr[0][i] = '.';
        arr[N+1][i] = '.';
    }
    for(int i=0;i<=N+1;i++) {
        arr[i][0] = '.';
        arr[i][M+1] = '.';
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if (arr[i][j] == 'W') {
                Func(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
struct sta {
    int x;
    int y;
};
void Func(int i,int j) {
    st[i][j]=true;
    stack <struct sta> s;
    if (arr[i-1][j-1] == 'W') {
        s.push({i-1,j-1});
        arr[i-1][j-1] = '.';
    }
    st[i-1][j-1]=true;
    if (arr[i-1][j] == 'W') {
        s.push({i-1,j});
        arr[i-1][j] = '.';
    }
    st[i-1][j] =true;
    if (arr[i-1][j+1] == 'W') {
        s.push({i-1,j+1});
        arr[i-1][j+1] = '.';
    }
    st[i-1][j+1]=true;
    if (arr[i][j-1] == 'W') {
        s.push({i,j-1});
        arr[i][j-1] = '.';
    }
    st[i][j-1]=true;
    if (arr[i][j+1] == 'W') {
        s.push({i,j+1});
        arr[i][j+1] = '.';
    }
    st[i][j+1]=true;
    if (arr[i+1][j-1] == 'W') {
        s.push({i+1,j-1});
        arr[i+1][j-1] = '.';
    }
    st[i+1][j-1]=true;
    if (arr[i+1][j] == 'W') {
        s.push({i+1,j});
        arr[i+1][j] = '.';
    }
    st[i+1][j]=true;
    if (arr[i+1][j+1] == 'W') {
        s.push({i+1,j+1});
        arr[i+1][j+1] = '.';
    }
    st[i+1][j+1]=true;
    arr[i][j] = '.';
    while(s.empty() == 0) {
        Func(s.top().x,s.top().y);
        s.pop();
    }
}
*/
/*
//1097. 池塘计数
#include <bits/stdc++.h>
using namespace std;
int M,N;
char arr[1005][1005];
bool st[1005][1005] = {false};
struct a {
    int x;
    int y;
};
void bfs(int i,int j) {
    ios_base::sync_with_stdio(false);
    queue<struct a> q;
    st[i][j] = true;
    q.push({i,j});
    while(!q.empty()) {
        for (int i1 = q.front().x-1; i1 <= q.front().x+1; i1++) {
            for (int j1 = q.front().y-1; j1 <= q.front().y+1; j1++) {
                if (i1 < 0 || i1 > N || j1 < 0 || j1 > M) continue;
                if (i1 == q.front().x && j1 == q.front().y) continue;
                if (arr[i1][j1] == 'W' && st[i1][j1] == false) {
                    q.push({i1, j1});
                }
                st[i1][j1] = true;
            }
        }
        q.pop();
    }
}
int main() {
    int ans =0 ;
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(arr[i][j]=='W' && st[i][j]==false) {
                bfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/